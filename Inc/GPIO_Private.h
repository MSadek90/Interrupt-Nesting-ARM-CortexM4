/*
 * GPIO_Private.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Sadek
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define MODE_MASK          0b11
#define MODER_PinMUL_x2       2u


#define PUPDR_MASK          0b11
#define PUPDR_PinMUL_x2       2u


#define OTYPE_MASK          0b1


#define OTSPEED_MASK          0b11
#define OTSPEED_PinMUL_x2       2u


#define ALT_FUNCTION_MASK          0b1111
#define ALT_FUNCTION_PinMUL_x4       4u
#endif /* GPIO_PRIVATE_H_ */
