/*
 * STM32F4xx.h
 *
 *  Created on: Dec 27, 2020
 *      Author: 99003152
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_
#define __vo volatile
#include <stdint.h>


//defining macros for various memory
#define FLASHADDR      0x08000000U
#define SRAM1ADDR 	   0x20000000U
#define SRAM2ADDR	   0x2001C000U
#define ROMADDR		   0x1FFF0000U
#define SRAM           SRAM1ADDR

//defining macros for busses
#define AHB1_BASEADDR		0x40020000U
#define AHB2_BASEADDR		0x50000000U
#define APB1_BASEADDR		0x40000000U
#define APB2_BASEADDR		0x40010000U
#define PERI_BASEADDR       APB1_BASEADDR

//defining macros for peripherals which is hanging on to AHB1 bus
#define GPIOA_BASEADDR		AHB1_BASEADDR //adding offsets to base address
#define GPIOB_BASEADDR      (AHB1_BASEADDR + (0x0400U))
#define GPIOC_BASEADDR      (AHB1_BASEADDR + (0x0800U))
#define GPIOD_BASEADDR      (AHB1_BASEADDR + (0x0C00U))
#define GPIOE_BASEADDR      (AHB1_BASEADDR + (0x1000U))
#define GPIOF_BASEADDR      (AHB1_BASEADDR + (0x1400U))
#define GPIOG_BASEADDR      (AHB1_BASEADDR + (0x1800U))
#define GPIOH_BASEADDR      (AHB1_BASEADDR + (0x1C00U))
#define GPIOI_BASEADDR      (AHB1_BASEADDR + (0x2000U))
#define RCC_ADDR         		(AHB1_BASEADDR + (0x3800U))

//I2C
#define I2C1_BASEADDR		(APB1_BASEADDR + (0X5400U))
#define I2C2_BASEADDR		(APB1_BASEADDR + (0X5800U))
#define I2C3_BASEADDR		(APB1_BASEADDR + (0X5C00U))

//SPI
#define SPI1_BASEADDR		(APB2_BASEADDR + (0x3000U))
#define SPI2_BASEADDR		(APB1_BASEADDR + (0x3800U))
#define SPI3_BASEADDR		(APB1_BASEADDR + (0x3C00U))

//UART
#define USART1_BASEADDR		(APB2_BASEADDR + (0x1000U))
#define USART2_BASEADDR		(APB1_BASEADDR + (0x4400U))
#define USART3_BASEADDR		(APB1_BASEADDR + (0x4800U))
#define UART4_BASEADDR		(APB1_BASEADDR + (0x4C00U))
#define UART5_BASEADDR		(APB1_BASEADDR + (0x5000U))
#define USART6_BASEADDR		(APB2_BASEADDR + (0x1400U))

//GPIO Peripheral registers
typedef struct {
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2]; //AFR[0] = low registers, AFR[1] = high registrers
}Reg_def_t;

//Reg_def_t *pGPIO = (Reg_def_t*)GPIOA_BASEADDR; //typecasting on RHS
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOB_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOC_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOD_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOE_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOF_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOG_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOH_BASEADDR;
//Reg_def_t *pGPIO = (Reg_def_t*)GPIOI_BASEADDR;

#define GPIOA (Reg_def_t*)GPIOA_BASEADDR
#define GPIOB (Reg_def_t*)GPIOB_BASEADDR
#define GPIOC (Reg_def_t*)GPIOC_BASEADDR
#define GPIOD (Reg_def_t*)GPIOD_BASEADDR
#define GPIOE (Reg_def_t*)GPIOE_BASEADDR
#define GPIOF (Reg_def_t*)GPIOF_BASEADDR
#define GPIOG (Reg_def_t*)GPIOG_BASEADDR
#define GPIOH (Reg_def_t*)GPIOH_BASEADDR
#define GPIOI (Reg_def_t*)GPIOI_BASEADDR
#define RCC   ((RCC_Reg_def_t*)RCC_ADDR)

typedef struct {
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t      RESERVED1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t      RESERVED2[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t      RESERVED3;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t      RESERVED4[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t      RESERVED5[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
}RCC_Reg_def_t;

//GPIO clock enable
#define GPIOA_PCLOCK_EN() RCC->AHB1ENR |= 1<<0
#define GPIOB_PCLOCK_EN() RCC->AHB1ENR |= 1<<1
#define GPIOC_PCLOCK_EN() RCC->AHB1ENR |= 1<<2
#define GPIOD_PCLOCK_EN() RCC->AHB1ENR |= 1<<3
#define GPIOE_PCLOCK_EN() RCC->AHB1ENR |= 1<<4;
#define GPIOF_PCLOCK_EN() RCC->AHB1ENR |= 1<<5;
#define GPIOG_PCLOCK_EN() RCC->AHB1ENR |= 1<<6;
#define GPIOH_PCLOCK_EN() RCC->AHB1ENR |= 1<<7;
#define GPIOI_PCLOCK_EN() RCC->AHB1ENR |= 1<<8;

//GPIO Clock disable

#define GPIOA_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0);
#define GPIOB_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0);
#define GPIOC_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0);
#define GPIOD_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0);
#define GPIOE_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0);
#define GPIOF_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0);
#define GPIOG_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0);
#define GPIOH_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0);
#define GPIOI_PCLOCK_DI() do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0);

//generic macros
#define ENABLE 			1
#define DISABLE			0
#define GPIO_Pin_set    ENABLE
#define GPIO_Pin_reset  DISABLE

#include "STM32Fxx_GPIO_driver.h"

#endif /* INC_STM32F4XX_H_ */
