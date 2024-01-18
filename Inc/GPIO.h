/*
 * GPIO.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Sadek
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>




typedef enum{
	PORTA=0,
    PORTB,
    PORTC,
    PORTD,
	PORTE,
    PORTF,
    PORTG,
	PORTH,
	NUM_OF_PORTS
}PORT_Type;



typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_Number;

typedef enum
{
	INPUT=0,
	OUTPUT,
	ALternate,
	Analog

}MODE_Type;

typedef enum
{
	Output_push_pull0=0,
	Output_open_Drain
}Output_Type;

typedef enum
{
	LOW_Speed=0,
    MEDUIM_Speed,
	FAST_Speed,
	HIGH_Speed
}Output_Speed_Type;




typedef enum
{
	NO_PULL_UP_DOWN=0,
    PULL_UP,
	PULL_DOWN

}PULL_UP_DOWN_Type;




typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,

}Alternate_Type;



typedef struct
{
	PORT_Type PORT;
	PIN_Number PIN;
	MODE_Type Mode;
	Output_Type OTYPE;
	Output_Speed_Type SPEED;
	PULL_UP_DOWN_Type P_UPDOWN;
	Alternate_Type ALT;

}PIN_CONFIG_T;


typedef enum
{
	ZERO=0,
	ONE,
}PIN_VALUE_T;

void GPIO_PinInit(PIN_CONFIG_T *P);
void GPIO_SetPinValue(PORT_Type port , PIN_Number number ,PIN_VALUE_T value);
uint8_t GPIO_Toggle(PORT_Type port , PIN_Number number);
uint8_t GPIO_READ_PIN(PORT_Type port,PIN_Number number,int* value);


#endif /* GPIO_H_ */
