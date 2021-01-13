/*
 * 2led.c
 *
 *  Created on: 29-Dec-2020
 *      Author: 99003152
 */

#include "STM32F4xx.h"
#include <stdint.h>

void delay(void)
{
	for(uint32_t i = 0; i<500000; i++);
}

int main()
{
GPIO_handle_t GPIOLED;
GPIOLED.pGPIOx = GPIOD;
GPIOLED.pin_config.GPIO_PinNumber = GPIO_Pin_Number_12;
GPIOLED.pin_config.GPIO_PinMode = GPIO_Mode_out;
GPIOLED.pin_config.GPIO_PinSpeed = GPIO_SpeedControl_high;
GPIOLED.pin_config.GPIO_PinOType = GPIO_OType_pushpull;
GPIOLED.pin_config.GPIO_PinPuPdControl = GPIO_PuPdControl_up;
GPIO_PeriClockControl(GPIOD, ENABLE);
GPIO_Init(&GPIOLED);

GPIO_handle_t GPIO_button;
GPIO_button.pGPIOx = GPIOA;
GPIO_button.pin_config.GPIO_PinNumber = GPIO_Pin_Number_0;
GPIO_button.pin_config.GPIO_PinMode = GPIO_Mode_in;
GPIO_button.pin_config.GPIO_PinSpeed = GPIO_SpeedControl_high;
//GPIO_button.pin_config.GPIO_PinPuPdControl = GPIO_PuPdControl_nothing;
GPIO_PeriClockControl(GPIOA, ENABLE);
GPIO_Init(&GPIO_button);

while(1)
{
	if((GPIO_ReadFromInputPin((Reg_def_t*)GPIOA_BASEADDR,GPIO_Pin_Number_0) == ENABLE))
	{
		//GPIO_Init(&GPIOLED);
	    GPIO_ToggleOutputPin((Reg_def_t*)GPIOD_BASEADDR, GPIO_Pin_Number_12);
	    delay();
	}
}
}



