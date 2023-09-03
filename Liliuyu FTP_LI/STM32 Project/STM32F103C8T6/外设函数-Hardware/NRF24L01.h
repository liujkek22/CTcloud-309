#ifndef __nRF24L01_API_H
#define __nRF24L01_API_H

#include "stm32f10x.h"                  // Device header

void NRF24L01_RT_Init(void);                                                //模块配置初始化
void NRF24L01_Pin_Init(void);                                               //模块引脚初始化
void NRF24L01_Init(void);                                                   //模块初始化
uint8_t NRF24L01_Check(void);                                               //检测模块是否存在
void NRF24L01_SendBuf(uint8_t *Buf);                                        //发送数据
uint8_t NRF24L01_Get_Value_Flag(void);                                      //获取IRQ标志位
//用户代码
uint8_t SPI_SwapByte(uint8_t byte);
uint8_t NRF24L01_Write_Reg(uint8_t reg,uint8_t value);
uint8_t NRF24L01_Read_Reg(uint8_t reg);
uint8_t NRF24L01_Read_Buf(uint8_t reg,uint8_t *pBuf, uint8_t len);
uint8_t NRF24L01_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t len);
uint8_t NRF24L01_GetRxBuf(uint8_t *rxbuf);
uint8_t NRF24L01_SendTxBuf(uint8_t *txbuf);
//模块代码

#endif
