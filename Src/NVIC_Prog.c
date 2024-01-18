#include "NVIC_Interface.h"
#include "NVIC_Reg.h"
#include "ErorrTypes.h"
#include <stdint.h>

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum;

	Local_u8RegNum = IRQn / 32; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	NVIC -> NVIC_ISER[Local_u8RegNum] = 1 << Local_u8BitNum;
}




void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum;

	Local_u8RegNum = IRQn / 32; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	NVIC -> NVIC_ICER[ Local_u8RegNum] = 1 << Local_u8BitNum;
}





void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum;

	Local_u8RegNum = IRQn / 32; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	NVIC -> NVIC_ISPR[ Local_u8RegNum] = 1 << Local_u8BitNum;
}





void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum;

	Local_u8RegNum = IRQn / 32; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	NVIC -> NVIC_ICPR[ Local_u8RegNum] = 1 << Local_u8BitNum;
}




uint8_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum, Local_u8PenStatus;

	Local_u8RegNum = IRQn / 32; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	Local_u8PenStatus = ((NVIC -> NVIC_ISPR[ Local_u8RegNum]>>Local_u8BitNum )& 1);

	return Local_u8PenStatus;
}


void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority)
{
	IPR[IRQn] = priority << 4;
}

uint8_t NVIC_GetPriority(IRQn_Type IRQn)
{
	uint8_t Local_u8RegNum, Local_u8BitNum, Local_u8PenStatus;

	Local_u8RegNum = IRQn / 4; /*get IRQn REG*/

	Local_u8BitNum = IRQn % 32; /* get Bit Num*/

	Local_u8PenStatus = ((NVIC -> NVIC_IPR[ Local_u8RegNum] >> Local_u8BitNum )&1);

	return Local_u8PenStatus;
}


uint8_t SCB_voidSetPriorityGroup(SCB_PRIORITY_G Copy_u8PriorityGroup)
{
	uint8_t Local_u8Error = OK;

	if(Copy_u8PriorityGroup > Safty_Start && Copy_u8PriorityGroup < Safty_End )
	{
	switch (Copy_u8PriorityGroup) {

	case _4_BitsGroupPriority_0_SubPriority:
		*((volatile uint32_t*)0xE000ED0C) = 0x05FA0300;
		break;

	case _3_BitsGroupPriority_1_SubPriority:
		*((volatile uint32_t*)0xE000ED0C) = 0x05FA0400;
		break;


	case _2_BitsGroupPriority_2_SubPriority:
		*((volatile uint32_t*)0xE000ED0C) = 0x05FA0500;
		break;

	case _1_BitsGroupPriority_3_SubPriority:
		*((volatile uint32_t*)0xE000ED0C) = 0x05FA0600;
		break;

	}
}
	else
	{
		Local_u8Error = NOK;
	}

	return Local_u8Error;
}
