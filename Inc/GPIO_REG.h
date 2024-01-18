/*
 * GPIO_REG.h
 *
 *  Created on: Nov 8, 2023
 *      Author: Sadek
 */

#ifndef GPIO_REG_H_
#define GPIO_REG_H_

typedef struct
{

volatile uint32_t MODER;
volatile uint32_t OTYPER;
volatile uint32_t OSPEEDER;
volatile uint32_t PUPDR;
volatile uint32_t IDR;
volatile uint32_t ODR;
volatile uint32_t BSRR;
volatile uint32_t LCKR;
volatile uint32_t AFR[2];

}GPIO_REG_TYPE;


#define GPIOA_BASE_Address     0x40020000U
#define GPIOB_BASE_Address     0x40020400U
#define GPIOC_BASE_Address     0x40020800U
#define GPIOD_BASE_Address     0x40020C00U
#define GPIOE_BASE_Address     0x40021000U
#define GPIOF_BASE_Address     0x40021400U
#define GPIOG_BASE_Address     0x40021800U
#define GPIOH_BASE_Address     0x40021C00U





#define GPIOA                            ((GPIO_REG_TYPE*)GPIOA_BASE_Address)
#define GPIOB                            ((GPIO_REG_TYPE*)GPIOB_BASE_Address)
#define GPIOC                            ((GPIO_REG_TYPE*)GPIOC_BASE_Address)
#define GPIOD                            ((GPIO_REG_TYPE*)GPIOD_BASE_Address)
#define GPIOE                            ((GPIO_REG_TYPE*)GPIOE_BASE_Address)
#define GPIOF                            ((GPIO_REG_TYPE*)GPIOF_BASE_Address)
#define GPIOG                            ((GPIO_REG_TYPE*)GPIOG_BASE_Address)
#define GPIOH                            ((GPIO_REG_TYPE*)GPIOH_BASE_Address)

#endif /* GPIO_REG_H_ */
