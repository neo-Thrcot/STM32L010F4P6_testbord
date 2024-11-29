#include "stm32l0xx.h"
#include "l010_gpio.h"

int main(void)
{
	Pin_Init(LD1, OUTPUT);

	while (1)
	{
		GPIO_Toggle_Pin(LD1);
		for (int i = 0; i < 100000; i++);
	}

	return 0;
}
