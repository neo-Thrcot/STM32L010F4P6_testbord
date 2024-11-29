#ifndef GPIO_L010_GPIO_H_
#define GPIO_L010_GPIO_H_

#include <stdint.h>
#include "stm32l0xx.h"
#include "gpio_define.h"

/*Address define*/
#define GPIOx_OFFSET		0x00000400UL
#define GPIOx_BASE(GPIOx)	(IOPPERIPH_BASE + GPIOx_OFFSET * GPIOx)

/*Init function*/
void GPIO_Clock_Enable(Port_t io_port);
void GPIO_Clock_Disable(Port_t io_port);
void Pin_Init(Pin_t io_pin, PinType_t io_function);

/*Output function*/
void GPIO_Out_Pin(Pin_t io_pin, bool pin_state);
void GPIO_Set_Pin(Pin_t io_pin);
void GPIO_Reset_Pin(Pin_t io_pin);
void GPIO_Toggle_Pin(Pin_t io_pin);

/*Input function*/


/*Inline function*/


#endif /* GPIO_L010_GPIO_H_ */
