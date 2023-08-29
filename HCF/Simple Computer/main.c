/*
接盘按键说明：
--------------------------------------------------
            |  1  |  2  |  3  |  +  |  
            - - - - - - - - - - - - -
            |  4  |  5  |  6  |  -  |
            - - - - - - - - - - - - -
            |  7  |  8  |  9  |  *  |
            - - - - - - - - - - - - -
			      | 0   |  CE |  =  |  /  | 
--------------------------------------------------*/
//操作简介
// 按第一个数，再按'+-*/',再按'='显示出结果，然后按C清屏
// 加最大9999+9999=19998
// 减最大9999-0   =9999
// 乘最大9999*9999=99980001
// 除 1/9=0.1111 保留小数点后4位
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
	
//--------LCD1602-------------------
//P00-07==== D0-7
sbit rs=P0^0;
sbit rw=P0^1;
sbit lcden=P0^2;
//--------LCD1602-------------------
//--------KEY-----------------------
//P1口
//--------KEY-----------------------
uchar code table[]="                ";

long int data_a,data_b;//第一个数和第二个数
long int data_c;//计算结果

uchar display[10];//  显示缓冲



void delay_ms(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)//执行x次循环
	{
		for(j=110;j>0;j--);//执行110次循环
	}
}

void delay_us(uint t)
{
    while(t--);     //t=0 ，退出
}


//************************************************************************/
// 描述：1602液晶写指令
//************************************************************************/
void write_com(uchar com)  //1602液晶写指令
{
    rs=0;                    //写指令
	lcden=0;                 //关使能
	P2=com;                  //写入指令com
	delay_ms(1);             //延时1ms
	lcden=1;                 //使能1602
	delay_ms(2);             //延时2ms
	lcden=0;                 //关使能
}

//************************************************************************/
//描述：1602液晶写数据
//************************************************************************/
void write_date(uchar date)//1602液晶写数据
{
    rs=1;                    //写数据
	lcden=0;                 //关使能 
	P2=date;                 //写入数据date
	delay_ms(1);             //延时1ms
	lcden=1;                 //使能1602
	delay_ms(2);             //延时2ms
	lcden=0;                 //关使能
}

//************************************************************************/
// 描述：指定x,y写入字符函数
//************************************************************************/
void W_lcd(unsigned char x,unsigned char y,unsigned char Data)
{
   if(y==0){write_com(0x80+x);} //第一行
   else{write_com(0xc0+x);}     //第二行
   write_date(Data);            //写入数据 
}	
//指定x,y写入字符串函数
void LCD_Write_String(unsigned char x,unsigned char y,unsigned char *s)
{
  if(y==0){write_com(0x80+x);} //第一行
   else{write_com(0xc0+x);}    //第二行
	while(*s)
	{write_date(*s);s++;}        //写入数据

}	

//************************************************************************/
// 描述：初始化液晶，及画面初始化
//************************************************************************/
void init_lcd(void)             //初始化液晶，及画面初始化
{
    rw=0;                        //写液晶
	lcden=0;                      //使能1602	
	write_com(0x38);              //8位总线，双行显示，5×7的点阵字符  
	delay_us(100);                //延时100us
	write_com(0x0c);              //开显示，无光标，光标不闪烁
	write_com(0x06);              //光标右移动
	write_com(0x01);              //清屏
	write_com(0x80);              //DD RAM 地址归0

}

//************************************************************************/
//描述：反转法键盘扫描
//************************************************************************/
short keycheckdown()            //反转法键盘扫描
{
  short temp1,temp2,temp,a=0xff;
	P1=0xf0;
	delay_ms(20);
	temp1=P1; //读列值
	P1=0xff;
	delay_ms(20);
	P1=0x0f;
	delay_ms(20);
	temp2=P1; //读行值
	P1=0xff;
	temp=(temp1&0xf0)|(temp2&0xff);//将两次读入数据组合
  switch(temp)	                  //通过读入数据组合判断按键位置
{

        case 0x77 :a=0xd;break;//  按键/   
		case 0xb7 :a=0xe;break;// 按键=	
		case 0xd7 :a=0xf;break;// 按键CE 
		case 0xe7 :a=0;break;// 按键0

		case 0x7b :a=0xc;break;// 	按键*
		case 0xbb :a=9;break; //  按键9
		case 0xdb :a=8;break; //  按键8 
		case 0xeb :a=7;break; // 	按键7

		case 0x7d :a=0xb;break;//  按键-
		case 0xbd :a=6;break; // 	按键6
		case 0xdd :a=5;break; // 	按键5
		case 0xed :a=4;break; // 	按键4

		case 0x7e :a=0xa; break;// 按键+
		case 0xbe :a=3;break;	   // 按键3
		case 0xde :a=2;break;	   // 按键2
		case 0xee :a=1;break;	   // 按键1

		default :a=0xff;
}
    return a;                //返回按键值

}	

void display_a() //显示数据a
{
  display[3]=data_a%10000/1000;    //千  
  display[2]=data_a%1000/100;      //百
	display[1]=data_a%100/10;        //十
	display[0]=data_a%10;            //个

  write_com(0x80+0);
	if(data_a>999){ write_date('0'+display[3]);}   //显示千位
	if(data_a>99){ write_date('0'+display[2]);}    //显示百位
	if(data_a>9){ write_date('0'+display[1]);}     //显示十位
                write_date('0'+display[0]);      //显示个位
}

void display_b()  //显示数据b
{

  write_com(0x80+7);               //第一行  
  display[3]=data_b%10000/1000;    //千  
  display[2]=data_b%1000/100;      //百
	display[1]=data_b%100/10;        //十
	display[0]=data_b%10;            //个

	if(data_b>999){ write_date('0'+display[3]);}   //显示千位
	if(data_b>99){ write_date('0'+display[2]);}    //显示百位
	if(data_b>9){ write_date('0'+display[1]);}     //显示十位
                write_date('0'+display[0]);      //显示个位

}

//计算结果
void display_c(x)
{

   if(data_c<100000000&&data_c>-1)//溢出时显示错误
	 {//display[8]=data_c%1000000000/100000000;    	//万万
		display[7]=data_c%100000000/10000000;    	//千万
		display[6]=data_c%10000000/1000000;    		//百万
		display[5]=data_c%1000000/100000;    		//十万
		display[4]=data_c%100000/10000;    			//万
		display[3]=data_c%10000/1000;    			//千
		display[2]=data_c%1000/100;      			//百
		display[1]=data_c%100/10;        			//十
		display[0]=data_c%10;            			//个 

		 write_com(0x80+6+0x40);//第一行  
		 if(x==4)
		 { 
			// if(data_c>99999999)	{	write_date('0'+display[8]);}    //显示万万
           if(data_c>9999999)	{	write_date('0'+display[7]);}      //千万
		   if(data_c>999999)	{	write_date('0'+display[6]);}      //百万
           if(data_c>99999)	    {write_date('0'+display[5]);}        //十万
								write_date('0'+display[4]);    //万
								write_date('.');
								write_date('0'+display[3]);    //千
								write_date('0'+display[2]);    //百
								write_date('0'+display[1]);    //十
								write_date('0'+display[0]);    //个 
		 }
    else{
		if(data_c>99999999)	{	write_date('0'+display[8]);}    //显示万万
		if(data_c>9999999)	{	write_date('0'+display[7]);}    //千万
		if(data_c>999999)	{	write_date('0'+display[6]);}    //百万
		if(data_c>99999)	{	write_date('0'+display[5]);}    //十万
		if(data_c>9999)		{	write_date('0'+display[4]);}    //万
		if(data_c>999)		{	write_date('0'+display[3]);}    //千
		if(data_c>99)		{	write_date('0'+display[2]);}    //百
		if(data_c>9)		{	write_date('0'+display[1]);}    //十
								write_date('0'+display[0]);          //个
	    	}
	 }
     else  //溢出时显示错误
	   {
		   write_com(0x80+11+0x40); //第一行
		   write_date('E');         //显示 E 
	     write_date('r');         //显示 R
       write_date('r');		 //显示 R
		   write_date('o');		 //显示 O
		   write_date('r');		 //显示 E
	    }	 
	 
}

void eql(uchar x)//加减乘除运算
{
    switch(x)   //功能键选择
		{
		  case 1:data_c=data_a+data_b;break; 		  //加 /* + S=1 */ /* 数值转换函数*/									
      case 2:if(data_a>=data_b){data_c=data_a-data_b;} /* - S=2 *///减
           else{data_c=data_b-data_a;W_lcd(5,1,'-');} //负数符号
					   break;  	 
			case 3:data_c=(data_a*data_b);break;		  /* * S=3 *///乘
			case 4:if(data_b==0){LCD_Write_String(0,1,"Error !");}else{data_c=(data_a*10000/data_b);}break;		  /* / S=4 *///3y//除//溢出时显示错误
			case 0:break;			
		}
}

void main()
{
  uchar key=0xff;         //键值初始化
  uchar n=0;              //第1个数可以按1-4次
	uchar m=5;              //第2个数可以按1-4次
	uchar x=0;
	data_a=0;               //前一个数
	data_b=0;               //后一个数
	data_c=0;               //结果
	init_lcd();             //1602液晶初始化 
	display_a();
	
    while(1)
 {
		  key=keycheckdown();
			if(key != 0xff)
		{
			if(key<10)
			{
		     if(n<4){data_a=data_a*10+key;m=5;display_a();}n++;
             if(m<4){data_b=data_b*10+key;n=5;display_b();}m++;
			}
			else
			{ switch(key)
			  {
				case 0xa:n=5;m=0;x=1;W_lcd(5,0,'+');break;
                case 0xb:n=5;m=0;x=2;W_lcd(5,0,'-');break;				
			    case 0xc:n=5;m=0;x=3;W_lcd(5,0,'*');break;
				case 0xd:n=5;m=0;x=4;W_lcd(5,0,'/');break;
				case 0xe:n=5;m=5;eql(x);W_lcd(12,0,'=');display_c(x);break;
				case 0xf:n=0;m=5;x=0;data_a=0;data_b=0;data_c=0;LCD_Write_String(0,0,table);LCD_Write_String(0,1,table);W_lcd(0,0,'0');break;
			  }
			}
			do{P1=0xf0;}while(P1!=0xf0);//按键被松开
		}//{0xff!=key}
   }//while
}//main

















