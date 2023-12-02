#ifndef _TEA5767_H_
#define _TEA5767_H_

/*——————————————操作位——————————*/
#define TEA5767_ADDR_W      0xc0    // TEA5767 写地址
#define TEA5767_ADDR_R      0xc1    // TEA5767 读地址

#define TEA5767_MAX_KHZ     108000  // 最高频率 108M
#define TEA5767_MIN_KHZ     87800   // 最低频率 87.5M

#define TEA5767_MUTE_ON     1       // 非静音
#define TEA5767_MUTE_OFF    0       // 静音

#define TEA5767_SEARCH_UP   1       // 向上搜索
#define TEA5767_SEARCH_DOWN 0       // 向下搜索

/*————————————全局变量——————————*/

extern unsigned long g_frequency;//频率

/*——————————————API——————————*/

void TEA5767_Init(void);
void TEA5767_Write(void);
void TEA5767_Read(void);
void TEA5767_GetPLL(void);
uint32_t TEA5767_GetFrequency(void);
void TEA5767_SetFrequency(uint32_t frequency);
void TEA5767_Search(uint8_t mode);
void TEA5767_AutoSearch(uint8_t mode);
void TEA5767_Mute(uint8_t mode);

#endif
