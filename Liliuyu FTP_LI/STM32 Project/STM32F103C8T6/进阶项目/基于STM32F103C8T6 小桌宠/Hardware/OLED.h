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
void OLED_ShowPicture(uint8_t Line, uint8_t Column, uint8_t x, uint8_t y,uint8_t Start);
void OLED_ShowGIF(uint8_t Num);
void OLED_ShowMyPicture(uint8_t Line, uint8_t Column, uint8_t x, uint8_t y,uint8_t Start);
#endif
