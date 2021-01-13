/*
 * STM32Fxx_GPIO_driver.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003152
 */

#ifndef INC_STM32FXX_GPIO_DRIVER_H_
#define INC_STM32FXX_GPIO_DRIVER_H_

#include "STM32F4xx.h"
#include <stdint.h>

//GPIO pin configuration
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOType;
	uint8_t GPIO_PinAltFuction;
}GPIO_PIN_CONFIG_t;

//GPIO handle structures (pin level)
typedef struct {
	Reg_def_t *pGPIOx;
	GPIO_PIN_CONFIG_t pin_config;
}GPIO_handle_t;

//GPIO pin numbers
#define GPIO_Pin_Number_0  0
#define GPIO_Pin_Number_1  1
#define GPIO_Pin_Number_2  2
#define GPIO_Pin_Number_3  3
#define GPIO_Pin_Number_4  4
#define GPIO_Pin_Number_5  5
#define GPIO_Pin_Number_6  6
#define GPIO_Pin_Number_7  7
#define GPIO_Pin_Number_8  8
#define GPIO_Pin_Number_9  9
#define GPIO_Pin_Number_10 10
#define GPIO_Pin_Number_11 11
#define GPIO_Pin_Number_12 12
#define GPIO_Pin_Number_13 13
#define GPIO_Pin_Number_14 14
#define GPIO_Pin_Number_15 15

//GPIO pin modes
#define GPIO_Mode_in 		0
#define GPIO_Mode_out 		1
#define GPIO_Mode_altFunc 	2
#define GPIO_Mode_Analog 	3
#define GPIO_Mode_IT_FT		4 //input trigger falling edge
#define GPIO_Mode_IT_RT		5
#define GPIO_Mode_IT_RFT		6

//GPIO pin output types
#define GPIO_OType_pushpull 	0
#define GPIO_OType_openDrain	1

//GPIO pin PuPdControl
#define GPIO_PuPdControl_nothing 	0
#define GPIO_PuPdControl_up 		1
#define GPIO_PuPdControl_down 		2
#define GPIO_PuPdControl_reserved   3

//GPIO pin speed control
#define GPIO_SpeedControl_slow 		0
#define GPIO_SpeedControl_medium 	1
#define GPIO_SpeedControl_high		2
#define GPIO_SpeedControl_verHigh	3

//GPIO pin Alternate function
#define GPIO_AltFunction_low_0  0
#define GPIO_AltFunction_low_1  1
#define GPIO_AltFunction_low_2  2
#define GPIO_AltFunction_low_3  3
#define GPIO_AltFunction_low_4  4
#define GPIO_AltFunction_low_5  5
#define GPIO_AltFunction_low_6  6
#define GPIO_AltFunction_low_7  7
#define GPIO_AltFunction_low_8  8
#define GPIO_AltFunction_low_9  9
#define GPIO_AltFunction_low_10 10
#define GPIO_AltFunction_low_11 11
#define GPIO_AltFunction_low_12 12
#define GPIO_AltFunction_low_13 13
#define GPIO_AltFunction_low_14 14
#define GPIO_AltFunction_low_15 15

#define GPIO_AltFunction_high_0  0
#define GPIO_AltFunction_high_1  1
#define GPIO_AltFunction_high_2  2
#define GPIO_AltFunction_high_3  3
#define GPIO_AltFunction_high_4  4
#define GPIO_AltFunction_high_5  5
#define GPIO_AltFunction_high_6  6
#define GPIO_AltFunction_high_7  7
#define GPIO_AltFunction_high_8  8
#define GPIO_AltFunction_high_9  9
#define GPIO_AltFunction_high_10 10
#define GPIO_AltFunction_high_11 11
#define GPIO_AltFunction_high_12 12
#define GPIO_AltFunction_high_13 13
#define GPIO_AltFunction_high_14 14
#define GPIO_AltFunction_high_15 15

//driver API's
void GPIO_PeriClockControl(Reg_def_t *pGPIOx, uint8_t EnorDi);

//init and deinit
void GPIO_Init(GPIO_handle_t *pGPIOHandle);
void GPIO_DeInit(Reg_def_t *pGPIOx);

//read and write
uint8_t GPIO_ReadFromInputPin(Reg_def_t *GPIOx,uint8_t PINNUMBER);
uint16_t GPIO_ReadFromInputPort(Reg_def_t *pGPIOx);
void GPIO_WriteToOutputPin(Reg_def_t *pGPIOx,uint8_t PINNUMBER,uint8_t Value);
void GPIO_ToggleOutputPin(Reg_def_t *pGPIOx,uint8_t PINNUMBER);



#endif /* INC_STM32FXX_GPIO_DRIVER_H_ */
