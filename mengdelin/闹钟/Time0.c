#include <REG51.H>
/**
  *@brief	 定时器0初始化，1毫秒@11.0592MHz
  *@param	无
  *@retval	无
  */
void Timer0_Init(void)		
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
	T0Count++;
	if(T0Count>=1000)						//定时多少毫秒（T0Count>=的值）
	{
		T0Count=0; 
		LED1=~LED1;
	}
}
*/
