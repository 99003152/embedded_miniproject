/*
 * DHT11.h
 *
 *  Created on: Dec 31, 2020
 *      Author: 99003152
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

void Set_Pin_Op (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Ip (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void DHT11_Strt (void);
uint8_t DHT11_Check_Resp (void);
uint8_t DHT11_read (void);

#endif /* INC_DHT11_H_ */
