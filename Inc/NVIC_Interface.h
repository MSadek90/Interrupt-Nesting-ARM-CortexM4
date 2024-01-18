






#ifndef NVIC_Interface_H_
#define NVIC_Interface_H_


#include <stdint.h>



typedef enum
{
	WWDG,
	PVD,
	EXTI0=6,
	EXTI1=7,
	TIM1_UP_TIM10=25,
	USART3=39
}IRQn_Type;




typedef enum
{
	Safty_Start=0,
	_4_BitsGroupPriority_0_SubPriority= 3,
	_3_BitsGroupPriority_1_SubPriority= 4,    /*group=0,1,2,3,4,5,6,7 // sub =0,1 */
	_2_BitsGroupPriority_2_SubPriority= 5,    /* group=0,1,2,3        // sub = 0,1,2,3*/
	_1_BitsGroupPriority_3_SubPriority= 6,    /* group=0,1            // sub = 0,1,2,3,4,5,6,7*/
    Safty_End=8
}SCB_PRIORITY_G;



void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint8_t NVIC_GetPendingIRQ(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority);
uint8_t NVIC_GetPriority(IRQn_Type IRQn);
uint8_t SCB_voidSetPriorityGroup(SCB_PRIORITY_G Copy_u8PriorityGroup);

#endif
