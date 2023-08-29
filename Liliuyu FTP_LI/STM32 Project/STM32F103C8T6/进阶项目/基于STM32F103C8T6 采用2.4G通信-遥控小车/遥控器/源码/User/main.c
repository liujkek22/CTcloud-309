#include "stm32f10x.h"                  // Device header
#include "Control.h"

int main(void)
{
    uint8_t CountL=0,CountR=0;
    Control_Init();
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
