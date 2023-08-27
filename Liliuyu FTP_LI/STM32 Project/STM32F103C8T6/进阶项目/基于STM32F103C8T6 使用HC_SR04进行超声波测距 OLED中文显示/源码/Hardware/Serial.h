#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <stdio.h>

extern char Serial_RxPacket[];
extern uint8_t Serial_RxFlag;

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array,uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number,uint8_t Lengeh);
void Serial_Printf(char *format, ...);

uint8_t Serial_GetRxFlag(void);
	
#endif
