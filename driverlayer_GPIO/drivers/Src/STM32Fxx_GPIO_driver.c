/*
 * STM32Fxx_GPIO_driver.c
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003152
 */

#include "STM32Fxx_GPIO_driver.h"
//driver API's
void GPIO_PeriClockControl(Reg_def_t *pGPIO, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
	    if (pGPIO == GPIOA)
	    {
			GPIOA_PCLOCK_EN();
	    }
		else if (pGPIO == GPIOB)
		{
			GPIOB_PCLOCK_EN();
		}
		else if(pGPIO == GPIOC)
		{
			GPIOC_PCLOCK_EN();
		}
		else if (pGPIO == GPIOD)
		{
			GPIOD_PCLOCK_EN();
		}
		else if (pGPIO == GPIOE)
		{
			GPIOE_PCLOCK_EN();
		}
		else if (pGPIO == GPIOF)
		{
			GPIOF_PCLOCK_EN();
		}
		else if(pGPIO == GPIOG)
		{
			GPIOG_PCLOCK_EN();
		}
		else if (pGPIO == GPIOH)
		{
			GPIOH_PCLOCK_EN();
		}
		else if (pGPIO == GPIOI)
		{
			GPIOI_PCLOCK_EN();
		}

	}
	else
	{
		        if (pGPIO == GPIOA)
			    {
					GPIOA_PCLOCK_DI();
			    }
				else if (pGPIO == GPIOB)
				{
					GPIOB_PCLOCK_DI();
				}
				else if(pGPIO == GPIOC)
				{
					GPIOC_PCLOCK_DI();
				}
				else if (pGPIO == GPIOD)
				{
					GPIOD_PCLOCK_DI();
				}
				else if (pGPIO == GPIOE)
				{
					GPIOE_PCLOCK_DI();
				}
				else if (pGPIO == GPIOF)
				{
					GPIOF_PCLOCK_DI();
				}
				else if(pGPIO == GPIOG)
				{
					GPIOG_PCLOCK_DI();
				}
				else if (pGPIO == GPIOH)
				{
					GPIOH_PCLOCK_DI();
				}
				else if (pGPIO == GPIOI)
				{
					GPIOI_PCLOCK_DI();
				}
	}


}

//init and deinit
void GPIO_Init(GPIO_handle_t *pGPIOHandle){
	//configuring the mode
	    uint32_t temp=0;
	    uint32_t temp1, temp2;
		if (pGPIOHandle->pin_config.GPIO_PinMode <= GPIO_Mode_Analog)
		{//non interrupt mode
		 temp = pGPIOHandle->pin_config.GPIO_PinMode<<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
		 pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2*pGPIOHandle->pin_config.GPIO_PinNumber));
		 pGPIOHandle->pGPIOx->MODER = temp;
		}
		if (pGPIOHandle->pin_config.GPIO_PinSpeed <= GPIO_SpeedControl_verHigh)
	    //configuring the speed
		{
		temp = pGPIOHandle->pin_config.GPIO_PinSpeed<<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR = temp;
		}

		if (pGPIOHandle->pin_config.GPIO_PinPuPdControl <= GPIO_PuPdControl_reserved)
	    // configuring the pullup pull down
		{
		temp = pGPIOHandle->pin_config.GPIO_PinPuPdControl<<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR = temp;
		}

	//configuring the output type
		if (pGPIOHandle->pin_config.GPIO_PinOType <= GPIO_OType_openDrain)
		{
		temp = pGPIOHandle->pin_config.GPIO_PinOType<<(pGPIOHandle->pin_config.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 <<(pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OTYPER = temp;
		}

	//configuring alternalte function

		if (pGPIOHandle->pin_config.GPIO_PinMode == GPIO_Mode_altFunc)
				{
					temp1 = pGPIOHandle->pin_config.GPIO_PinNumber/8;
					temp2 = pGPIOHandle->pin_config.GPIO_PinNumber%8;
				    //temp = pGPIOHandle->pin_config.GPIO_PinAltFuction<<(temp2);
				    //pGPIOHandle->pGPIOx->AFR[temp1] = temp;
					pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2));
				    pGPIOHandle->pGPIOx->AFR[temp1] |=pGPIOHandle->pin_config.GPIO_PinAltFuction<<(4*temp2);
				}

}
void GPIO_DeInit(Reg_def_t *pGPIOx)
{
	if (pGPIOx == GPIOA)
				    {
						GPIOA_PCLOCK_DI();
				    }
					else if (pGPIOx == GPIOB)
					{
						GPIOB_PCLOCK_DI();
					}
					else if(pGPIOx == GPIOC)
					{
						GPIOC_PCLOCK_DI();
					}
					else if (pGPIOx == GPIOD)
					{
						GPIOD_PCLOCK_DI();
					}
					else if (pGPIOx == GPIOE)
					{
						GPIOE_PCLOCK_DI();
					}
					else if (pGPIOx == GPIOF)
					{
						GPIOF_PCLOCK_DI();
					}
					else if(pGPIOx == GPIOG)
					{
						GPIOG_PCLOCK_DI();
					}
					else if (pGPIOx == GPIOH)
					{
						GPIOH_PCLOCK_DI();
					}
					else if (pGPIOx == GPIOI)
					{
						GPIOI_PCLOCK_DI();
					}

}

//read and write
uint8_t GPIO_ReadFromInputPin(Reg_def_t *GPIOx,uint8_t PINNUMBER)
{
  uint8_t value;
  value = (uint8_t)(GPIOx->IDR>>PINNUMBER)*(0x00000001);
  return value;
}
uint16_t GPIO_ReadFromInputPort(Reg_def_t *pGPIOx)
{
	uint16_t value1;
	value1 = (uint16_t)(pGPIOx->IDR);
	return value1;
}
void GPIO_WriteToOutputPin(Reg_def_t *pGPIOx,uint8_t PINNUMBER,uint8_t Value)
{
	if(Value == GPIO_Pin_set)
	{
		pGPIOx->ODR |= (1<< PINNUMBER);
	}
	else
	{
		pGPIOx->ODR &= ~(1<< PINNUMBER);
	}
}
void GPIO_WriteToOutputPort(Reg_def_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(Reg_def_t *pGPIOx,uint8_t PINNUMBER)
{
	pGPIOx->ODR = pGPIOx->ODR ^ (1<<PINNUMBER);
}
