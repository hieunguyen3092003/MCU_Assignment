/*
 * global.c
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#include "global.h"


int status = 0;
int red_time = 5;
int green_time = 3;
int yellow_time = 2;

//SET TRAFFIC LIGHT FUNCTION
void setTrafficRed()
{
	HAL_GPIO_WritePin(LIGHT2_GPIO_Port, LIGHT2_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT3_GPIO_Port, LIGHT3_Pin, SET);
}
void setTrafficGreen()
{
	HAL_GPIO_WritePin(LIGHT2_GPIO_Port, LIGHT2_Pin, SET);
	HAL_GPIO_WritePin(LIGHT3_GPIO_Port, LIGHT3_Pin, RESET);
}
void setTrafficYellow()
{
	HAL_GPIO_WritePin(LIGHT2_GPIO_Port, LIGHT2_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT3_GPIO_Port, LIGHT3_Pin, RESET);
}

void setTrafficRed1()
{
	HAL_GPIO_WritePin(LIGHT4_GPIO_Port, LIGHT4_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT5_GPIO_Port, LIGHT5_Pin, SET);

}
void setTrafficGreen1()
{
	HAL_GPIO_WritePin(LIGHT4_GPIO_Port, LIGHT4_Pin, SET);
	HAL_GPIO_WritePin(LIGHT5_GPIO_Port, LIGHT5_Pin, RESET);
}
void setTrafficYellow1()
{
	HAL_GPIO_WritePin(LIGHT4_GPIO_Port, LIGHT4_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT5_GPIO_Port, LIGHT5_Pin, RESET);
}
// PED CONTROL
void setPedLightRed()
{
	HAL_GPIO_WritePin(PED_LIGHT1_GPIO_Port, PED_LIGHT1_Pin, RESET);
	HAL_GPIO_WritePin(PED_LIGHT2_GPIO_Port, PED_LIGHT2_Pin, SET);
}
void setPedLightYellow()
{
	HAL_GPIO_WritePin(PED_LIGHT1_GPIO_Port, PED_LIGHT1_Pin, RESET);
	HAL_GPIO_WritePin(PED_LIGHT2_GPIO_Port, PED_LIGHT2_Pin, RESET);
}
void setPedLightGreen()
{
	HAL_GPIO_WritePin(PED_LIGHT1_GPIO_Port, PED_LIGHT1_Pin, SET);
	HAL_GPIO_WritePin(PED_LIGHT2_GPIO_Port, PED_LIGHT2_Pin, RESET);
}
void setPedLightOff()
{
	HAL_GPIO_WritePin(PED_LIGHT1_GPIO_Port, PED_LIGHT1_Pin, SET);
	HAL_GPIO_WritePin(PED_LIGHT2_GPIO_Port, PED_LIGHT2_Pin, SET);
}
// toggle control
void toggleTrafficRed()
{
	HAL_GPIO_TogglePin(LIGHT2_GPIO_Port, LIGHT2_Pin);
	HAL_GPIO_TogglePin(LIGHT4_GPIO_Port, LIGHT4_Pin);
}
void toggleTrafficYellow()
{
	HAL_GPIO_TogglePin(LIGHT2_GPIO_Port, LIGHT2_Pin);
	HAL_GPIO_TogglePin(LIGHT3_GPIO_Port, LIGHT3_Pin);
	HAL_GPIO_TogglePin(LIGHT4_GPIO_Port, LIGHT4_Pin);
	HAL_GPIO_TogglePin(LIGHT5_GPIO_Port, LIGHT5_Pin);
}
void toggleTrafficGreen()
{
	HAL_GPIO_TogglePin(LIGHT3_GPIO_Port, LIGHT3_Pin);
	HAL_GPIO_TogglePin(LIGHT5_GPIO_Port, LIGHT5_Pin);
}

int led_buffer[4] = {1, 2, 3, 4};
void setLedBuffer(int first_led_time, int second_led_time)
{
	led_buffer[0] = first_led_time / 10;
	led_buffer[1] = first_led_time % 10;
	led_buffer[2] = second_led_time / 10;
	led_buffer[3] = second_led_time % 10;
}

void updateLedBuffer()
{
	//TODO
	if(led_buffer[1] <= 0)
	{
		led_buffer[0]--;
		led_buffer[1] = 9;
	}
	else
	{
		led_buffer[1]--;
	}
	if(led_buffer[3] <= 0)
	{
		led_buffer[2]--;
		led_buffer[3] = 9;
	}
	else
	{
		led_buffer[3]--;
	}
}

void resetInitialState()
{
	HAL_GPIO_WritePin(GPIOB, PED_LIGHT1_Pin|LIGHT3_Pin|LIGHT4_Pin|LIGHT5_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, PED_LIGHT2_Pin|LIGHT2_Pin, SET);

	timer1_flag = 0;
	timer2_flag = 0;
	timer3_flag = 0;
	timer4_flag = 0;

	isButton1Pressed(); // delete all button_flag
	isButton2Pressed();
	isButton3Pressed();
	isButton4Pressed();
}
