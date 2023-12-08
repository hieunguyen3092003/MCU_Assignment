/*
 * global.h
 *
 *  Created on: Nov 30, 2023
 *      Author: hieun
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"
#include "FSMLightModification.h"
#include "FSMModificationMode.h"
#include "FSMNormalMode.h"
#include "FSMPedestrianMode.h"
#include "scheduler.h"
#include "softwareTimer.h"
#include "UART.h"

//define các trạng thái của máy trạng thái
#define INIT				1
#define AUTO_RED			2
#define AUTO_GREEN			3
#define AUTO_YELLOW			4

#define MAN_RED				12
#define MAN_GREEN			13
#define MAN_YELLOW			14

#define NORMAL_MODE			21
#define RED0_GREEN1			22
#define RED0_YELLOW1 		23
#define GREEN0_RED1  		24
#define YELLOW0_RED1 		25

#define MODIFICATION_MODE	31
#define MODIFY_RED			32
#define MODIFY_GREEN		33
#define MODIFY_YELLOW		34

#define MODIFY_TIME_RED		42
#define MODIFY_TIME_GREEN	43
#define MODIFY_TIME_YELLOW	44

extern int status;
extern int red_time;
extern int green_time;
extern int yellow_time;

#define TOGGLE_TIME			250

//SET TRAFFIC LIGHT FUNCTION
void setTrafficRed();
void setTrafficGreen();
void setTrafficYellow();

void setTrafficRed1();
void setTrafficGreen1();
void setTrafficYellow1();

void setPedLightRed();
void setPedLightYellow();
void setPedLightGreen();
void setPedLightOff();

void toggleTrafficRed();
void toggleTrafficGreen();
void toggleTrafficYellow();

//INTERACT WITH SEVEN SEG LED FUNCTION
const int scan_led_time;
int led_buffer[4];
void setLedBuffer(int first_led_time, int second_led_time);
void updateLedBuffer();
void scanSevenSeg(int number);
void sevenSegDisplay();


void resetInitialState();

#endif /* INC_GLOBAL_H_ */
