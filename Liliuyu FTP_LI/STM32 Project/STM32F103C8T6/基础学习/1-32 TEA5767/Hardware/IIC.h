#ifndef _IIC_H_
#define _IIC_H_

void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_SendByte(uint8_t Byte);
uint8_t IIC_ReceiveByte(void);
void IIC_SendAck(uint8_t AckBit);
uint8_t IIC_ReceiveAck(void);
uint8_t IIC_WaitAck(void);
void IIC_Ack(void);
void IIC_NO_Ack(void);

#endif
