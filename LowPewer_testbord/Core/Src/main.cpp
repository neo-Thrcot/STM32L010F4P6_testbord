#include "stm32l0xx.h"
#include "l010_gpio.h"

int main(void)
{
	Pin_Init(LD1, OUTPUT);
	Pin_Init(SW1, INPUT);

	while (1)
	{
		bool sw_state = GPIO_Input_Pin(SW1);
		GPIO_Out_Pin(LD1, sw_state);
	}

	return 0;
}
