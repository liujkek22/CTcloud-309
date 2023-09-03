#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	Serial_Init();
	
	Serial_Printf("愿所有美好与你相伴\r\n");
	
	while(1)
	{
		
	}
}	
