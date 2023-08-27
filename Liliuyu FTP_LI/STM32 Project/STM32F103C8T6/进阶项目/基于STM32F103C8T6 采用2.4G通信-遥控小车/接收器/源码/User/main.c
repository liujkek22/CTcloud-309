#include "stm32f10x.h"                  // Device header
#include "Control.h"

int main(void)
{
    Control_Init();
    while(1)
    {
        Control();
    }

}
