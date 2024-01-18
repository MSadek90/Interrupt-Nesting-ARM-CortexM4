/*
 * GPIO.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Sadek
 */



#include "GPIO.h"
#include "GPIO_Private.h"
#include "ErorrTypes.h"
#include "GPIO_REG.h"


/****************************************************************************************/
/* @FN GPIO_PinInit
 * @ brief the function initialize the pin according to the input parameter
 * @parameter [in] PIN_CONFIG_T : the initialization value of the pin
 * @return Error_status
 */
static GPIO_REG_TYPE *Array[NUM_OF_PORTS]={GPIOA,//stm32f446r
		                            GPIOB,
									GPIOC,
									GPIOD,
									GPIOE,
									GPIOF,
									GPIOG,
									GPIOH
                                   };


void GPIO_PinInit(PIN_CONFIG_T * p)
{


       /* Select GPIO Mode : Input, Output, ALternate Function, Analog */

		(Array[p->PORT]->MODER) &= ~(MODE_MASK <<(p->PIN   *  MODER_PinMUL_x2));   //Clear Mode Bits
		(Array[p->PORT]->MODER) |= (p->Mode << (p->PIN * MODER_PinMUL_x2)); // Set value in Bits


	/* Select GPIO pull mode : Pull Up , Pull Down , No Pull */

		(Array[p->PORT]->PUPDR) &= ~(PUPDR_MASK <<(p->PIN * PUPDR_PinMUL_x2));   /*Clear Mode Bits*/
		(Array[p->PORT]->PUPDR) |= (p->P_UPDOWN << (p->PIN * PUPDR_PinMUL_x2)); /* Set value in Bits*/



		/* Select output type || output speed in case of general purpose output or alternate function */
		if(p ->Mode == OUTPUT || p ->Mode == ALternate)
		{
			/* Select output type : pull up or open drain */

			(Array[p->PORT]->OTYPER &= ~(OTYPE_MASK << p->PIN));
			(Array[p->PORT]->OTYPER |= (p->OTYPE << p->PIN));


			/* Select output speed : LOW, MEDUIM, HIGH, FAST */

			(Array[p->PORT]->OSPEEDER &= ~(OTSPEED_MASK << p->PIN * OTSPEED_PinMUL_x2));
			(Array[p->PORT]->OSPEEDER |= (p->SPEED << p->PIN * OTSPEED_PinMUL_x2));

			/*Select ALT Function */

           if(p ->Mode == ALternate)
           {


			(Array[p->PORT]->AFR[(p->PIN)/8] &= ~( ALT_FUNCTION_MASK  << ( p->PIN % 8 ) * ALT_FUNCTION_PinMUL_x4 ));
			(Array[p->PORT]->AFR[(p->PIN)/8] |= ( ALT_FUNCTION_MASK  << ( p->PIN % 8 ) * ALT_FUNCTION_PinMUL_x4 ));

           }
		}
	}


void GPIO_SetPinValue(PORT_Type port , PIN_Number number ,PIN_VALUE_T value)
{

	if(port < NUM_OF_PORTS && number<=PIN15)
	{
	switch(value)
	{
	case ZERO:
		Array[port]-> ODR &= ~(1<<number);
		break;

	case ONE:
		Array[port]-> ODR |= (1<<number);
		break;



	}

	}
}

uint8_t GPIO_PinToggle(PORT_Type port , PIN_Number number)
{
	uint8_t local_Errorstate=OK;
	if(port < NUM_OF_PORTS && number<=PIN15)
	{
		Array[port]->ODR ^=1<<number;
	}

	else
	{
		local_Errorstate=NOK;
	}

	return local_Errorstate;

}

uint8_t GPIO_READ_PIN(PORT_Type port,PIN_Number number ,int *value)
{
	uint8_t local_Errorstate=OK;
	if(port < NUM_OF_PORTS && number<=PIN15)
	{
		*value = ((Array[port]->IDR >> number) & 1);
	}
	else
	{
		local_Errorstate=NOK;
	}
	return local_Errorstate;
}

