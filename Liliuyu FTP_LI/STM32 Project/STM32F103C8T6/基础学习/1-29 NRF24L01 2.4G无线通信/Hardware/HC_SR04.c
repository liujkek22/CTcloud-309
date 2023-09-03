#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "HC_SR04.h"

uint32_t HC_Count;//间隔计数，与定时器计数间隔有关，目前是1MS

void HC_SR04_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//引脚组
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//计时器
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure.GPIO_Pin = TRIG;//触发测距
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度
	GPIO_Init(HC_SR04_PROT,&GPIO_InitStructure);//初始化触发引脚
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉输入模式
	GPIO_InitStructure.GPIO_Pin = ECHO;//回响信号
	GPIO_Init(HC_SR04_PROT,&GPIO_InitStructure);//初始化回响引脚
	
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;//不分频
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_InitStructure.TIM_Period = 1000-1;//ARR,设置结果为1MS进一次中断
	TIM_InitStructure.TIM_Prescaler = 72-1;//SPC,预分频系数
	TIM_InitStructure.TIM_RepetitionCounter = DISABLE;//禁用自动重装
	TIM_TimeBaseInit(TIM2,&TIM_InitStructure);//初始化计时定时器
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//清空标志位,设置是否分频时会立刻触发标志位
	
	TIM_ITConfig(TIM2,TIM_FLAG_Update|TIM_IT_Trigger,ENABLE);//开启上拉标志位和引脚的中断触发
	TIM_Cmd(TIM2,DISABLE);//关闭计时器
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//中断分组
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//次优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能中断
	NVIC_Init(&NVIC_InitStructure);//中断初始化
	
}

void TIM2_IRQHandler(void)//测量回响时间
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) !=0)//不为0时产生中断
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);//清除中断标志
		HC_Count++;
	}
}

void HC_SR04_Distance(uint16_t *dataA,uint16_t *dataB)
{
	uint32_t Count= 0;
	
	while(GPIO_ReadInputDataBit(HC_SR04_PROT,ECHO) == 1);//读取引脚状态,不为高电平时继续，此时HC_SR04无信号
	GPIO_SetBits(HC_SR04_PROT,TRIG);
	Delay_us(20);//给予20微妙的高电平TTL信号，触发回响
	GPIO_ResetBits(HC_SR04_PROT,TRIG);//解除信号
	
	while(GPIO_ReadInputDataBit(HC_SR04_PROT,ECHO) == 0);//读取引脚状态,不为低电平时继续，此时HC_SR04接收回响
	TIM_SetCounter(TIM2,0);//定时器计数器置0
	HC_Count = 0;//计数器置0
	TIM_Cmd(TIM2,ENABLE);//开启定时器
	
	while(GPIO_ReadInputDataBit(HC_SR04_PROT,ECHO) == 1);//读取引脚状态,不为高电平时继续，此时HC_SR04接收回响完毕
	TIM_Cmd(TIM2,DISABLE);//关闭计数器
	
	Count = HC_Count * 1000;//转换完微秒us
	Count = Count + TIM_GetCounter(TIM2);//总时间，TIM_GetCounter获取定时器的CNT值，单位值间隔1us
	
	*dataA = Count / 58;//公式转换厘米				    //距离公式
	*dataB = Count * 0.017;//340/1000000us  340/s/2*100//声速公式
	
}

uint16_t HC_SR04_avange(void)
{
	uint16_t dataA =0, dataB =0; 
	uint32_t dataNA =0,dataNB =0;
	
	HC_SR04_Distance(&dataA,&dataB);
	for(uint8_t i=0; i<5; i++)
		{
			dataNA = dataNA + dataA;//数据累计
			dataNB = dataNB + dataB;
		}
	return (dataNA+dataNB)/5;
}
