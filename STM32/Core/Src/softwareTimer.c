/*
 * softwareTimer.c
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#include "softwareTimer.h"


int timer1_counter = 0;
int timer1_flag = 0;
void setTimer1(int duration) // THIS TIMER ONLY USE FOR SET FLAG TRAFFICLIGHT (already multiple for 100)
{
	timer1_counter = duration*100;
	timer1_flag = 0;
}

int timer2_counter = 0;
int timer2_flag = 0;
void setTimer2(int duration2)
{
	timer2_counter = duration2;
	timer2_flag = 0;
}

int timer3_counter = 0;
int timer3_flag = 0;
void setTimer3(int duration3) // THIS TIMER ONLY USE FOR SET FLAG TRAFFICLIGHT
{
	timer3_counter = duration3;
	timer3_flag = 0;
}

int timer4_counter = 0;
int timer4_flag = 0;
void setTimer4(int duration4)
{
	timer4_counter = duration4;
	timer4_flag = 0;
}


void timerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter--;

		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}

	if(timer2_counter > 0)
	{
		timer2_counter--;//counter led 7 segment

		if(timer2_counter <= 0) // counter led 7 segment
		{
			timer2_flag = 1;
		}
	}

	if(timer3_counter > 0)
	{
		timer3_counter--;

		if(timer3_counter <= 0)
		{
			timer3_flag = 1;
		}
	}

	if(timer4_counter > 0)
	{
		timer4_counter--;
		if(timer4_counter <= 0)
		{
			timer4_flag = 1;
		}
	}

}
