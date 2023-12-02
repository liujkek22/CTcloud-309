#include "stm32f10x.h"                  // Device header
#include "final.h"
#include "OLED.h"

int main(void)
{
    Final_Init();
    while(1)
    {
        crol();
    }
}

