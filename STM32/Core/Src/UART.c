/*
 * UART.c
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#include "UART.h"

extern UART_HandleTypeDef huart2;

/*brief: init uart interrupt if the system received data
 * para: none
 * retval: none
 * */
void uart_Init(void) {
	return;
}
/*brief: send the current mode once.
 * para: mode - the current number mode
 * retval: none
 * */
void uart_SendMode(uint8_t mode) {
	if (mode > 4 || mode == 0)
		return;
	char str[45];
	uint16_t len = sprintf(str, "!MODE:%d#\n", mode);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, len, 10);
}
/*brief: send the traffic light timer in traffic mode
 * para: 	id - the index of traffic light 0 or 1
 * 			number - the value of timers
 * retval: none
 * */
void uart_SendTimeTraffic(uint8_t id, uint16_t number) {
	if (id > 1)
		return;
	char str[20];
	uint16_t len = sprintf(str, "!7SEG%d:%d#\n", id, number);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, len, 10);
}
/*brief: send the red buffer in RED_ADJUSTMENT
 * para:	number - the value of buffers
 * retval: none
 * */
void uart_SendBufferRed(uint16_t number) {
	char str[20];
	uint16_t len = sprintf(str, "!RED:%d#\n", number);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, len, 10);
}
/*brief: send the green buffer in GREEN_ADJUSTMENT
 * para:	number - the value of buffers
 * retval: none
 * */
void uart_SendBufferGreen(uint16_t number) {
	char str[20];
	uint16_t len = sprintf(str, "!GREEN:%d#\n", number);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, len, 10);
}
/*brief: send the yellow buffer in YELLOW_ADJUSTMENT
 * para:	number - the value of buffers
 * retval: none
 * */
void uart_SendBufferYellow(uint16_t number) {
	char str[20];
	uint16_t len = sprintf(str, "!YELLOW:%d#\n", number);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, len, 10);
}
