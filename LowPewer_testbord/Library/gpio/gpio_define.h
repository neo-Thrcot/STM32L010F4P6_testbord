#ifndef GPIO_GPIO_DEFINE_H_
#define GPIO_GPIO_DEFINE_H_

typedef enum {
	PORTA	= 0x00U,
	PORTB,
	PORTC
} Port_t;

typedef enum {
	PA0		= 0x00U,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA9,
	PA13,
	PA14,
	PB1 	= 0x11U,
	PB9		= 0x19U,
	PC14	= 0x2EU,
	PC15
} Pin_t;

typedef enum {
	INPUT		= 0,
	OUTPUT,
	ALTERNATE,
	ANALOG
} PinType_t;

/*IO states*/
#define LOW		false
#define HIGH	true

/*Reserved I/O pin*/
#define	LD1		PB1
#define SW1		PB9

#endif /* GPIO_GPIO_DEFINE_H_ */
