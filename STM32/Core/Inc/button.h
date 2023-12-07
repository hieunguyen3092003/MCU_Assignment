/*
 * button.h
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET // macro nay thay the normal state thanh tin hieu muc 1
#define PRESSED_STATE GPIO_PIN_RESET // macro thay tin hieu muc 0 luc nhan

//extern int button1_flag;

int isButton1Pressed();

int isButton2Pressed();

int isButton3Pressed();

void getKeyInput();


#endif /* INC_BUTTON_H_ */
