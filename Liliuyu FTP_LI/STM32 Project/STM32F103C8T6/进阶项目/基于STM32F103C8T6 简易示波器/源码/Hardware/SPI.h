#ifndef _SPI_H_
#define _SPI_H_

void SPI2_Init(void);			        //��ʼ��SPI2
void SPI2_SetSpeed(uint8_t SpeedSet);        //����SPI�ٶ�   
void SPI2_ReadWriteByte(uint8_t TxData);     //SPI���߶�дһ���ֽ�
void SPI_Start(void);
void SPI_Stop(void);

#endif
