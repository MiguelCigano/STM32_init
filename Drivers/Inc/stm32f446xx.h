/*
 * stm32f446xx.h
 *
 *  Created on: Mar 24, 2024
 *      Author: jmiguel-nitro
 */

#ifndef DRIVERS_INC_STM32F446XX_H_
#define DRIVERS_INC_STM32F446XX_H_

/*
 * Aquí comenzamos a meter los defines que vayamos creando
 */

#include <stdint.h>

#define ENABLE	1
#define DISABLE	0

#define SET		1
#define RESET	0

#define AHB1PERIPH_BASEADOR 0X40020000UL

#define GPIOA_BASEADOR		(AHB1PERIPH_BASEADOR + 0x0000)
#define GPIOB_BASEADOR		(AHB1PERIPH_BASEADOR + 0x0400)
#define GPIOC_BASEADOR		(AHB1PERIPH_BASEADOR + 0x0800)
#define GPIOD_BASEADOR		(AHB1PERIPH_BASEADOR + 0x0C00)
#define GPIOE_BASEADOR		(AHB1PERIPH_BASEADOR + 0x1000)
#define GPIOF_BASEADOR		(AHB1PERIPH_BASEADOR + 0x1400)
#define GPIOG_BASEADOR		(AHB1PERIPH_BASEADOR + 0x1800)
#define GPIOH_BASEADOR		(AHB1PERIPH_BASEADOR + 0x1C00)

#define RCC_BASEADOR		(AHB1PERIPH_BASEADOR + 0x3800)

/*
 * Se define una estructura que contenga todos los registros de cada periférico
 * con sus respectivos offsets
 */

typedef struct{
	
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
	
}GPIO_RegDef_t;


typedef struct{

	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;

	uint32_t RES0;

	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;

	uint32_t RES1;
	uint32_t RES2;

	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;

	uint32_t RES3;

	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;

	uint32_t RES4;
	uint32_t RES5;

	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;

	uint32_t RES6;

	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;

	uint32_t RES7;
	uint32_t RES8;

	volatile uint32_t BDCR;
	volatile uint32_t CSR;

	uint32_t RES9;
	uint32_t RES10;

	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

/* Definición de perifericos */

#define GPIOA		((GPIO_RegDef_t *)GPIOA_BASEADOR)
#define GPIOB		((GPIO_RegDef_t *)GPIOB_BASEADOR)
#define GPIOC		((GPIO_RegDef_t *)GPIOC_BASEADOR)
#define GPIOD		((GPIO_RegDef_t *)GPIOD_BASEADOR)
#define GPIOE		((GPIO_RegDef_t *)GPIOE_BASEADOR)
#define GPIOF		((GPIO_RegDef_t *)GPIOF_BASEADOR)
#define GPIOG		((GPIO_RegDef_t *)GPIOG_BASEADOR)
#define GPIOH		((GPIO_RegDef_t *)GPIOH_BASEADOR)

#define RCC			((RCC_RegDef_t *)RCC_BASEADOR)

/* Macros para habilitar clock de perifericos, ponen a uno */

#define GPIOA_EN_CLK()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_EN_CLK()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_EN_CLK()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_EN_CLK()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_EN_CLK()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_EN_CLK()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_EN_CLK()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_EN_CLK()		(RCC->AHB1ENR |= (1 << 7))

/* Desahabilitar el clock de perifericos, ponen a cero  */

#define GPIOA_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 7))

/* Macros para el reset del puerto */

#define GPIOA_RESET()		do{RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0);}while(0)
#define GPIOB_RESET()		do{RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1);}while(0)
#define GPIOC_RESET()		do{RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2);}while(0)
#define GPIOD_RESET()		do{RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3);}while(0)
#define GPIOE_RESET()		do{RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4);}while(0)
#define GPIOF_RESET()		do{RCC->AHB1RSTR |= (1 << 5); RCC->AHB1RSTR &= ~(1 << 5);}while(0)
#define GPIOG_RESET()		do{RCC->AHB1RSTR |= (1 << 6); RCC->AHB1RSTR &= ~(1 << 6);}while(0)
#define GPIOH_RESET()		do{RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7);}while(0)


#endif /* DRIVERS_INC_STM32F446XX_H_ */
