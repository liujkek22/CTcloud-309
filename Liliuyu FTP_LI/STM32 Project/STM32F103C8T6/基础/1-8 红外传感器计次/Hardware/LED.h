#ifndef _LED_H_
#define _LED_H_

void LED_Init(void);//LED1初始化
void LED1_ON(void);//LED1开 所对应引脚设置低电平
void LED1_OFF(void);//LED1关 锁对应引脚设置高电平
void LED1_Turn(void);//LED1电平信号翻转 之前为高则变为低，之前为低则变为高
void LED2_ON(void);
void LED2_OFF(void);
void LED2_Turn(void);

#endif
