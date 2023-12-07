/*
 * UART.h
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include"stm32f1xx_hal.h"
#include <stdio.h>

void uart_SendMode(uint8_t mode);
void uart_Init(void);
void uart_SendTimeTraffic(uint8_t id, uint16_t number);
void uart_SendBufferRed(uint16_t number);
void uart_SendBufferGreen(uint16_t number);
void uart_SendBufferYellow(uint16_t number);

#endif /* INC_UART_H_ */
