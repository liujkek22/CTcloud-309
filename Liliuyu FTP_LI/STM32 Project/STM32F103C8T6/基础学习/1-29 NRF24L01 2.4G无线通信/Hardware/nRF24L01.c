#include "stm32f10x.h"                  // Device header
#include "NRF24L01_Reg.h"
#include "NRF24L01.h"
#include "sys.h"
#include "Delay.h"

//	while(1)
//	{
//        SEND_BUF(A);
//        Delay_ms(2000);
//        SEND_BUF(B);
//        Delay_ms(2000);
//        SEND_BUF(C);
//        Delay_ms(2000);
//	}//接收使用方案

//    while(1)
//	{
//		
//	  if( PBin(1) == 0) //如果检测到开始接收数据
//	  {
//		NRF24L01_RxPacket(C); //将数据放入数组C
//	  }
//	  
//	    OLED_ShowHexNum(2,5,C[0],2);
//	}//发送使用方案


#define TX_ADR_WIDTH    5                                        //5字节地址宽度
#define RX_ADR_WIDTH    5                                        //5字节地址宽度
#define TX_PLOAD_WIDTH  32                                       //32字节有效数据宽度
#define RX_PLOAD_WIDTH  32                                       //32字节有效数据宽度

const uchar TX_ADDRESS[TX_ADR_WIDTH]={0xFF,0xFF,0xFF,0xFF,0xFF}; //发送地址
const uchar RX_ADDRESS[RX_ADR_WIDTH]={0xFF,0xFF,0xFF,0xFF,0xFF}; //发送地址


#define NRF_CSN   PAout(4)      //片选信号，推挽输出  ，		                        接PA4
#define NRF_SCK   PAout(5)      //发送接收模式选择推挽输出,                             接PA5
#define NRF_MISO  PAin(6)       //PC7 MISO  					                        接PA6
#define NRF_MOSI  PAout(7)      //PC6 MOSI 主机推挽输出 （根据速率初始化PC_CR2寄存器）, 接PA7
#define NRF_CE    PBout(0)      //PC5 推完输出,				                            接PB0
#define NRF_IRQ   PBin(1)       //IRQ主机数据输入,上拉输入		                        接PB1
//使用软件SPI，可通过修改此宏定义和端口初始化更改引脚

void NRF24L01_Init(void)//初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;  			//IRQ中断引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
    //引脚初始化
    
    NRF_CE=0;		  
  	NRF24L01_Write_Reg(nRF_WRITE_REG+RX_PW_P0,RX_PLOAD_WIDTH);                          //选择通道0的有效数据宽度
	NRF24L01_Write_Reg(FLUSH_RX,0xff);									                //清除RX FIFO寄存器,0xff是没用的  
  	NRF24L01_Write_Buf(nRF_WRITE_REG+TX_ADDR,(uchar*)TX_ADDRESS,TX_ADR_WIDTH);          //写TX节点地址 
  	NRF24L01_Write_Buf(nRF_WRITE_REG+RX_ADDR_P0,(uchar*)RX_ADDRESS,RX_ADR_WIDTH);       //设置TX节点地址,主要为了使能ACK	  
  	NRF24L01_Write_Reg(nRF_WRITE_REG+EN_AA,0x01);                                       //使能通道0的自动应答    
  	NRF24L01_Write_Reg(nRF_WRITE_REG+EN_RXADDR,0x01);                                   //使能通道0的接收地址  
  	NRF24L01_Write_Reg(nRF_WRITE_REG+SETUP_RETR,0x1a);                                  //设置自动重发间隔时间:500us + 86us;最大自动重发次数:10次
  	NRF24L01_Write_Reg(nRF_WRITE_REG+RF_CH,0);                                          //设置RF通道为2.400GHz  频率=2.4+0GHz
  	NRF24L01_Write_Reg(nRF_WRITE_REG+RF_SETUP,0x0F);                                    //设置TX发射参数,0db增益,2Mbps,低噪声增益开启   
  	NRF24L01_Write_Reg(nRF_WRITE_REG+CONFIG,0x0f);                                      //配置基本工作模式的参数;PWR_UP,EN_CRC,16BIT_CRC,接收模式,开启所有中断
	NRF_CE=1;									                                        //CE置高，使能发送
    //配置初始化
}

uchar SPI_RW(uchar byte)  //读写寄存器地址
{
	uchar bit_ctr;
	for(bit_ctr=0;bit_ctr<8;bit_ctr++)                                                  // 输出8位
	{                                          
		if((uchar)(byte&0x80)==0x80)                                           
		NRF_MOSI=1; 			                                                        // MSB TO MOSI，高位先行
		else                                           
			NRF_MOSI=0;                                            
		byte=(byte<<1);					                                                // 高位先行
		NRF_SCK=1;						                                                //高电平时相互交换数据
		byte|=NRF_MISO;	        		                                                // 记录nrf24l01发送来的字节
		NRF_SCK=0;						                                                //拉低时钟
	}
	return byte;
}

uchar NRF24L01_Write_Reg(uchar reg,uchar value)//给24L01的寄存器写值（一个字节）,reg   要写的寄存器地址,value 给寄存器写的值
{
	uchar status;

	NRF_CSN=0;                                 //CSN=0;   
  	status = SPI_RW(reg);		               //发送寄存器地址,并读取状态值
	SPI_RW(value);				               //先写寄存器，再写值
	NRF_CSN=1;                                 //CSN=1;

	return status;//返回状态值
}

uchar NRF24L01_Read_Reg(uchar reg)//读24L01的寄存器值 （一个字节），reg  要读的寄存器地址，value 读出寄存器的值
{
 	uchar value;

	NRF_CSN=0;                                  //CSN=0;   
  	SPI_RW(reg);			                    //发送寄存器值(位置),并读取状态值
	value = SPI_RW(NOP);                    
	NRF_CSN=1;             	                    //CSN=1;

	return value;//返回value 读出寄存器的值
}

uchar NRF24L01_Read_Buf(uchar reg,uchar *pBuf,uchar len)//读24L01的寄存器值（多个字节），reg   寄存器地址，*pBuf 读出寄存器值的存放数组，len   数组字节长度
{
	uchar status,u8_ctr;
	NRF_CSN=0;                   	            //CSN=0       
	status=SPI_RW(reg);				            //发送寄存器地址,并读取状态值   	   
 	for(u8_ctr=0;u8_ctr<len;u8_ctr++)
	pBuf[u8_ctr]=SPI_RW(0XFF);		            //读出数据
	NRF_CSN=1;                 		            //CSN=1
	return status;        			            //返回读到的状态值
}

uchar NRF24L01_Write_Buf(uchar reg, uchar *pBuf, uchar len)//给24L01的寄存器写值（多个字节），reg  要写的寄存器地址，*pBuf 值的存放数组，len   数组字节长度  
{
	uchar status,u8_ctr;
	NRF_CSN=0;   					            //CSN低电平写
	status = SPI_RW(reg);			            //发送寄存器值(位置),并读取状态值
  for(u8_ctr=0; u8_ctr<len; u8_ctr++)
	SPI_RW(*pBuf++); 				            //写入数据
	NRF_CSN=1;
  return status;          		                //返回读到的状态值
}							  					   

uchar NRF24L01_RxPacket(uchar *rxbuf)//24L01接收数据
{
	uchar state;
	state=NRF24L01_Read_Reg(STATUS);  			            //读取状态寄存器的值    	 
	NRF24L01_Write_Reg(nRF_WRITE_REG+STATUS,state);         //0x20+STATUS是指向状态寄存器，state是为了，如果标志位置1那执行该程序就会清除中断
	if(state&RX_OK)								            //RX_OK是0x40，这里是判断接收
	{
		NRF_CE = 0;											//好像CE使能配置端，CE为低电平，配置的才有用。而CSN是使能写数据端，低电平才能写数据
		NRF24L01_Read_Buf(RD_RX_PLOAD,rxbuf,RX_PLOAD_WIDTH);//读取数据，好像读数据不用拉高CE,只有发送才要
		NRF24L01_Write_Reg(FLUSH_RX,0xff);					//清除RX FIFO寄存器
		NRF_CE = 1;					
		Delay_us(150);
		return 0; //成功收到数据 
	}	   
	return 1;//没收到任何数据
}

uchar NRF24L01_TxPacket(uchar *txbuf)//24L01发送数据，txbuf  发送数据数组
{
	uchar state;
   
	NRF_CE=0;												            //CE拉低，使能24L01配置，此时才可以写TX（TX在配置里面）
  	NRF24L01_Write_Buf(WR_TX_PLOAD,txbuf,TX_PLOAD_WIDTH);	            //写数据到TX BUF  32个字节
 	NRF_CE=1;												            //CE置高，使能发送，拉高为发送
	while(NRF_IRQ==1);										            //等待发送完成
	state=NRF24L01_Read_Reg(STATUS);  						            //读取状态寄存器的值	   
	NRF24L01_Write_Reg(nRF_WRITE_REG+STATUS,state); 			        //清除TX_DS或MAX_RT中断标志，好像不是复位成0
	if(state&MAX_TX)				 						            //如果达到最大重发次数
	{       
		NRF24L01_Write_Reg(FLUSH_TX,0xff);					            //清除TX FIFO寄存器，直接清空数据，不要了
		return MAX_TX;                                                  //达到最大重发次数，发送失败
	}       
	if(state&TX_OK)											            //发送完成
	{       
		return TX_OK;       
	}       
	return 0xff;											            //发送失败
}
  
uchar NRF24L01_Check(void)//检测24L01是否存在
{
	uchar check_in_buf[5]={0x11,0x22,0x33,0x44,0x55};
	uchar check_out_buf[5]={0x00};

	NRF_SCK=0;
	NRF_CSN=1;    //不写配置
	NRF_CE=0;	  //使能配置

	NRF24L01_Write_Buf(nRF_WRITE_REG+TX_ADDR, check_in_buf, 5);	//写TX

	NRF24L01_Read_Buf(nRF_READ_REG+TX_ADDR, check_out_buf, 5);	//读TX

	if((check_out_buf[0] == 0x11)&&\
	   (check_out_buf[1] == 0x22)&&\
	   (check_out_buf[2] == 0x33)&&\
	   (check_out_buf[3] == 0x44)&&\
	   (check_out_buf[4] == 0x55))return 0;//存在 
	else return 1;//不存在
}			

void SEND_BUF(uchar *buf)//发送数据包
{
	NRF_CE=0;										        //写寄存器时候要把CE拉低
	NRF24L01_Write_Reg(nRF_WRITE_REG+CONFIG,0x0e);   
	NRF_CE=1;
	Delay_us(15);
	NRF24L01_TxPacket(buf);						
	NRF_CE=0;
	NRF24L01_Write_Reg(nRF_WRITE_REG+CONFIG, 0x0f);		    //转换为接收模式
	NRF_CE=1;	
}
