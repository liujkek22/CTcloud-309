#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowChineseString(uint8_t Line, uint8_t Column, uint8_t Start, uint8_t End);
void OLED_ShowPicture(uint8_t Line, uint8_t Column, uint8_t x, uint8_t y);
void OLED_ShowGIF(uint8_t Num);
void OLED_SetCursor(uint8_t Y, uint8_t X);//����
void OLED_WriteData(uint8_t Data);//������ʾ����    
void OLED_ShowBMP(u8 x0,u8 y0,u8 x1,u8 y1,uint8_t BMP[]);//��ʾͼƬ
void OLED_Refresh(void);//ˢ���Դ�
void OLED_GFill(void);
void OLED_GClear(void);
void OLED_DrawPoint(unsigned char x,unsigned char y);//���������
void OLED_ClearPoint(unsigned char x,unsigned char y);//Ϩ�������
void FourPoints(u8 xstart,u8 ystart);//�ҶȲ�������0��0����1��0����0��1����1��1����
void ADCWave(uint8_t step);
#endif
