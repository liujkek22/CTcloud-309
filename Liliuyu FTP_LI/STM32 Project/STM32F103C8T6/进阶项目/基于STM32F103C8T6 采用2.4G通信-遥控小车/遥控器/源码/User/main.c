#include "stm32f10x.h"                  // Device header
#include "Control.h"

int main(void)
{
    uint8_t CountL=0,CountR=0;
    Control_Init();
    OLED_ShowPicture(1,1,128,64);
    OLED_ShowChineseString(2,7,0,0);
    Delay_ms(500);
    OLED_ShowChineseString(3,7,1,1);
    Delay_ms(500);
    OLED_ShowChineseString(4,7,2,2);
    Delay_ms(2500);
    OLED_ShowChineseString(2,8,3,3);
    OLED_ShowChineseString(3,8,4,4);
    Delay_ms(1000);
	OLED_Clear();
	OLED_Base();//显示基础界面
    while (1) 
    {
        if(AD_Value[0] > 3000)
        {
            Delay_ms(300);
            CountL++;
        }
        if(AD_Value[0] < 1000)
        {
            Delay_ms(300);
            CountL++;
        }        
        if(Key_GetNum() == 1)
        {
            CountR++;
        }
        if (Control((CountL%2),(CountR%2))==4)
        {
            CountR = 0;
        }
    }
}
