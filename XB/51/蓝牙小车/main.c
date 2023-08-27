#include<reg52.h>

#define uchar unsigned char 
#define uint unsigned int

sbit leftA1=P0^0;
sbit leftA2=P0^1;

sbit leftB1=P0^2;
sbit leftB2=P0^3;

sbit rightA1=P0^4;
sbit rightA2=P0^5;

sbit rightB1=P0^6;
sbit rightB2=P0^7;

sbit led1=P1^2;
sbit led2=P1^3;

sbit fmq1=P1^4;
sbit fmq2=P1^5;


void led()
{
led1=1;led2=0;
}


void ledm()
{
led1=0;led2=0;
}

void fmq()
{
fmq1=1;fmq2=0;
}

void car_stop()//停止
{
leftA1=1;   leftA2=1;
leftB1=1;   leftB2=1;
rightA1=1;  rightA2=1;
rightB1=1;  rightB2=1;
}

void car_advance()//前进
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=0;
rightB1=1;  rightB2=0;
}

void car_retreat()//后退
{
leftA1=0;   leftA2=1;
leftB1=0;   leftB2=1;
rightA1=0;  rightA2=1;
rightB1=0;  rightB2=1;
}

void car_left_advance()//左前进
{
leftA1=1;   leftA2=1;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=0;
rightB1=1;  rightB2=1;
}

void car_right_advance()//右前进
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=1;
rightA1=1;  rightA2=1;
rightB1=1;  rightB2=0;
}

void car_left_retreat()//左后退
{
leftA1=0;   leftA2=1;
leftB1=1;   leftB2=1;
rightA1=1;  rightA2=1;
rightB1=0;  rightB2=1;	
}
void car_right_retreat()//右后退
{
leftA1=1;   leftA2=1;
leftB1=0;   leftB2=1;
rightA1=0;  rightA2=1;
rightB1=1;  rightB2=1;	
}

void left_translation()//左平移
{
leftA1=0;   leftA2=1;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=0;
rightB1=0;  rightB2=1;
}

void right_translation()//右平移
{
leftA1=1;   leftA2=0;
leftB1=0;   leftB2=1;
rightA1=0;  rightA2=1;
rightB1=1;  rightB2=0;
}

void left1_cycle()//以左前轮为定点顺时针转圈
{
leftA1=1;   leftA2=1;
leftB1=1;   leftB2=1;
rightA1=1;  rightA2=0;
rightB1=1;  rightB2=0;
}

void left2_cycle()//以左后轮为定点顺时针转圈
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=1;
rightA1=1;  rightA2=0;
rightB1=1;  rightB2=1;
}

void right1_cycle()//以右前轮为定点顺时针转圈
{
leftA1=1;   leftA2=1;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=1;
rightB1=1;  rightB2=0;
}

void right2_cycle()//以右后轮为定点顺时针转圈
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=1;
rightB1=1;  rightB2=1;
}

void cycle_centre()//以小车中心为定点顺时针转圈
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=0;
rightA1=0;  rightA2=1;
rightB1=0;  rightB2=1;
}

void back_whell_cycle()//以后轮中心为定点顺时针转圈
{
leftA1=1;   leftA2=0;
leftB1=1;   leftB2=1;
rightA1=0;  rightA2=1;
rightB1=1;  rightB2=1;
}

void ahead_whell_cycle()//以前轮中心为定点顺时针转圈
{
leftA1=1;   leftA2=1;
leftB1=1;   leftB2=0;
rightA1=1;  rightA2=1;
rightB1=0;  rightB2=1;
}




uint i;
uchar code table[] = "I got "; // 前缀字符串，用于回复计算机
uchar c;
void init()
{
    TMOD = 0x20; // 设置定时器1为8位自动重载模式
    TH1 = 0xfd; // 设置波特率为9600bps（11.0592MHz晶振）
    TL1 = 0xfd;
    TR1 = 1; // 启动定时器1
    REN = 1; // 允许串口接收
    SM0 = 0; // 设置串口为模式1（8位数据位，无校验位，1位停止位）
    SM1 = 1;
    EA = 1; // 开启总中断
    ES = 1; // 开启串口中断
}

void main()
{
    car_stop();
	
    init(); // 初始化串口和定时器

    while (1) {
        if (RI) { // 判断是否收到计算机发送的数据
            RI = 0;
					
					
					
					
					switch(c)//接收蓝牙数据
  {
   case 'A': car_left_advance(); fmq(); led();         break;
   case 'B': car_advance() ;        led(); fmq();      break;
   case 'C': car_right_advance();  led(); fmq();       break;
   case 'D': left_translation();   led(); fmq();       break;
   case 'E':  car_stop();           led(); fmq();      break; 
	 case 'F':  right_translation();  led(); fmq();      break;
	 case 'G':  car_left_retreat();   led(); fmq();      break;
	 case 'H':  car_retreat();        led(); fmq();      break;
	 case 'I':  car_right_retreat();  led(); fmq();      break;
	 case 'J':  left1_cycle();       led(); fmq();       break;
	 case 'K':  ahead_whell_cycle(); led(); fmq();       break;
	 case 'L':  right1_cycle();      led(); fmq();       break;
	 case 'M':  cycle_centre();      led(); fmq();       break;
	 case 'N':  left2_cycle();       led(); fmq();       break;
	 case 'O':  back_whell_cycle();  led(); fmq();       break;
	 case 'P':  right2_cycle();      led(); fmq();       break;	 
	 default:   car_stop();          ledm();             break;
  }		
				
           
					
					
            ES = 0; // 关闭串口中断，防止发送数据时触发中断
            for (i = 0; i < 6; i++) {
                SBUF = table[i]; // 发送前缀字符串
                while (!TI); // 等待发送完成
                TI = 0; // 清除发送完成标志位
            }
            SBUF = c; // 发送收到的字符
            while (!TI);
            TI = 0;
            ES = 1; // 开启串口中断
        }
    }
}

void ser() interrupt 4
{
	  c = SBUF; // 读取计算机发送的数据
	
}




