#ifndef _FINAL_H_
#define _FINAL_H_

void Final_Init(void);
void crol(void);
void move_restop(void);
void move_rest(void); 
void move_stop(void);
void move_gohead(void);
void move_headpack(uint8_t Angle);
void move_goback(void);
void move_backpack(uint8_t Angle);
void move_right(void);
void move_rightpack(uint8_t Angle);
void move_leftpack(uint8_t Angle);
void move_shakehand(void);
void move_shakebody(void);
void move_chek(void);
//桌宠运动控制

void OLED_Show_eyes_round(void);    
void OLED_Show_eyes_crash(void);
void OLED_Show_eyes_confot(void);
//表情显示控制

#endif
