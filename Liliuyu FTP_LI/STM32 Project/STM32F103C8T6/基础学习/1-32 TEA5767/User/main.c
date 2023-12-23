#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "key.h"
#include "TEA5767.h"

int main(void)
{
	OLED_Init();
    Key_Init();
    TEA5767_Init();
	while(1)
	{
		OLED_ShowNum(1,1,g_frequency,6);
        if(Key_GetNum()==1)
        {
            TEA5767_Search(1);
        }
        else if(Key_GetNum()==2)  
        {
            TEA5767_Search(2);
        }
	}
}
