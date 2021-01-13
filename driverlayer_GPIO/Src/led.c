/*
 * led.c
 *
 *  Created on: 29-Dec-2020
 *      Author: 99003152
 */

#include "STM32F4xx.h"
//#include "STM32Fxx_GPIO_driver.h"



void delay(void)
{
	for(uint32_t i = 0; i<500000; i++);
}
int main()
{
GPIO_handle_t GPIOLED;
GPIOLED.pGPIOx = GPIOD;
GPIOLED.pin_config.GPIO_PinNumber = GPIO_Pin_Number_15;
GPIOLED.pin_config.GPIO_PinMode = GPIO_Mode_out;
GPIOLED.pin_config.GPIO_PinSpeed = GPIO_SpeedControl_high;
GPIOLED.pin_config.GPIO_PinOType = GPIO_OType_pushpull;
GPIOLED.pin_config.GPIO_PinPuPdControl = GPIO_PuPdControl_up;
GPIO_PeriClockControl(GPIOD, ENABLE);
GPIO_Init(&GPIOLED);

while(1)
{
	GPIO_ToggleOutputPin(GPIOD, 15);
	delay();
}
}


