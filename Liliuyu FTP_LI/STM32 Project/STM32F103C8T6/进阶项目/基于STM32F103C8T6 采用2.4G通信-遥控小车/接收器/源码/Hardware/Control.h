#ifndef _Control_H_
#define _Control_H_

#include "OLED.h"                   //显示，0.96存OLED(I2C协议)
#include "NRF24L01.h"               //2.4G通信，NRF24L01
#include "L298N.h"                  //L298N电机驱动

void Control_Init(void);
void Control(void);


#endif
