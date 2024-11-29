#include "l010_gpio.h"

static bool portA_Clock = false;
static bool portB_Clock = false;
static bool portC_Clock = false;

void GPIO_Clock_Enable(Port_t io_port)
{
	switch (io_port) {
		case PORTA:
			if (portA_Clock == false) {
				RCC -> IOPENR |= (1 << 0);
				portA_Clock = true;
			}
			break;

		case PORTB:
			if (portB_Clock == false) {
				RCC -> IOPENR |= (1 << 1);
				portB_Clock = true;
			}
			break;

		case PORTC:
			if (portC_Clock == false) {
				RCC -> IOPENR |= (1 << 2);
				portC_Clock = true;
			}
			break;

		default:
			break;
	}
}

void GPIO_Clock_Disable(Port_t io_port)
{
	switch (io_port) {
		case PORTA:
			if (portA_Clock == true) {
				RCC -> IOPENR &= (~(1 << 0));
				portA_Clock = false;
			}
			break;

		case PORTB:
			if (portB_Clock == true) {
				RCC -> IOPENR &= (~(1 << 1));
				portB_Clock = false;
			}
			break;

		case PORTC:
			if (portC_Clock == true) {
				RCC -> IOPENR &= (~(1 << 2));
				portC_Clock = false;
			}
			break;

		default:
			break;
	}
}

void Pin_Init(Pin_t io_pin, PinType_t io_function)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return;
	}

	GPIO_Clock_Enable((Port_t)port_num);
	((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> MODER &= (~(0b11U << (pin_num * 2)));
	((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> MODER |= (io_function << (pin_num * 2));
}

void GPIO_Out_Pin(Pin_t io_pin, bool pin_state)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return;
	}

	if (pin_state == LOW) {
		((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> ODR &= (~(1 << pin_num));
	} else if (pin_state == HIGH) {
		((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> ODR |= (1 << pin_num);
	}
}

void GPIO_Set_Pin(Pin_t io_pin)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> ODR |= (1 << pin_num);
}

void GPIO_Reset_Pin(Pin_t io_pin)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> ODR &= (~(1 << pin_num));
}

void GPIO_Toggle_Pin(Pin_t io_pin)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return;
	}

	((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> ODR ^= (1 << pin_num);
}

bool GPIO_Input_Pin(Pin_t io_pin)
{
	uint8_t port_num	= ((io_pin & (0xF0U)) >> 4);
	uint8_t pin_num		= (io_pin & (0x0FU));

	if (port_num > 2) {
		return 0;
	}

	return (((GPIO_TypeDef*)(GPIOx_BASE(port_num))) -> IDR & (1 << pin_num)) >> pin_num;
}
