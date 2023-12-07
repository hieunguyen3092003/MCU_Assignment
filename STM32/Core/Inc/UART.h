/*
 * UART.h
 *
 *  Created on: Dec 8, 2023
 *      Author: bach
 */



#ifndef INC_UART_H_
#define INC_UART_H_


#include"stm32f1xx_hal.h"
#include <stdio.h>

void uart_Init(void);
void UARTSendMode(uint8_t mode);
void UARTCountdownTrafficTime(uint8_t id,uint16_t time);
void UARTSendBufferRed(uint16_t number) ;
void uart_SendBufferGreen(uint16_t number);
void uart_SendBufferYellow(uint16_t number);

#endif /* INC_UART_H_ */
