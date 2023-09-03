#ifndef __nRF24L01_H
#define __nRF24L01_H

#include "NRF24L01_Reg.h"
#define uchar unsigned char
#define uint unsigned int
uchar SPI_RW(uchar byte);//读写寄存器地址
uchar NRF24L01_Write_Reg(uchar reg,uchar value);//给24L01的寄存器写值（一个字节）
uchar NRF24L01_Read_Reg(uchar reg);//读24L01的寄存器值 （一个字节）
uchar NRF24L01_Read_Buf(uchar reg,uchar *pBuf,uchar len);//读24L01的寄存器值（多个字节）
uchar NRF24L01_Write_Buf(uchar reg, uchar *pBuf, uchar len);//给24L01的寄存器写值（多个字节）
uchar NRF24L01_RxPacket(uchar *rxbuf);//24L01接收数据
uchar NRF24L01_TxPacket(uchar *txbuf);//24L01发送数据
uchar NRF24L01_Check(void);//检测24L01是否存在
void SEND_BUF(uchar *buf);//发送数据包
void NRF24L01_Init(void);//初始化

#endif
