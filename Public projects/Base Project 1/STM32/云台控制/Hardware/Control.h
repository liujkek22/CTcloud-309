#ifndef _Control_H_
#define _Control_H_

#include "OLED.h"                   //显示，0.96存OLED(I2C协议)
//#include "NRF24L01.h"               //2.4G通信，NRF24L01
#include "AD.h"                     //摇杆数据，HW-504
//#include "MPU6050.h"                //体感控制，MPU6050
#include "key.h"                    //按键操作部分
#include "Delay.h"
#include "PWM.h"

void Control_Init(void);
uint8_t Yao_Gan_Control(void);
uint8_t Ti_Gan_Control(void);
uint8_t Control(uint8_t mod,uint8_t come);
void OLED_Base(void);
void OLED_Base_Y(void);
void OLED_Base_T(void);

#endif
