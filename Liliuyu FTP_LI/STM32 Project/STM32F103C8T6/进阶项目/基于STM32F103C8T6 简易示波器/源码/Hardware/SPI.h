#ifndef _SPI_H_
#define _SPI_H_

void SPI2_Init(void);			        //初始化SPI2
void SPI2_SetSpeed(uint8_t SpeedSet);        //设置SPI速度   
void SPI2_ReadWriteByte(uint8_t TxData);     //SPI总线读写一个字节
void SPI_Start(void);
void SPI_Stop(void);

#endif
