#ifndef _LED_H_
#define _LED_H_

#define LED_PORT GPIOB
#define LED_1 GPIO_Pin_3
#define LED_2 GPIO_Pin_4
#define LED_3 GPIO_Pin_5
#define LED_4 GPIO_Pin_6
/* 引脚定义区 */

void LED_Init(void);
void LED_1_W(uint8_t BitValue);
void LED_2_W(uint8_t BitValue);
void LED_3_W(uint8_t BitValue);
void LED_4_W(uint8_t BitValue);
void LED_ALL_W(uint8_t BitValue);               

#endif
