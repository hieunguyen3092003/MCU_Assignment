/*
 * FSMNormalMode.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Khoi
 */

#ifndef SRC_FSMNORMALMODE_C_
#define SRC_FSMNORMALMODE_C_

#include "FSMNormalMode.h"


void FSMNormalModeRun()
{
	switch(status)
	{
	case NORMAL_MODE:
		resetInitialState(); 	// reset all all the varialbles thats affect FSMNormalModeRun

		status = RED0_GREEN1; 	//next mode
		setTimer1(green_time);	//set timer for next state
		setTimer2(100);
		timer2_flag = 1;
		setTimer3(100);
		setLedBuffer(red_time, green_time);

		// uart
		UARTSendMode(1);
		break;
	case RED0_GREEN1:
		setTrafficRed();
		setTrafficGreen1();

		if(timer3_flag == 1)	//update buffer every second
		{
			updateLedBuffer();
			setTimer3(100);
		}

		//uart
		if(timer2_flag == 1)
		{
			UARTCountdownTrafficTime(1, (led_buffer[0] * 10) + led_buffer[1]);
			UARTCountdownTrafficTime(2, (led_buffer[2] * 10) + led_buffer[3]);
			setTimer2(100);
		}

		if(timer1_flag == 1)
		{
			status = RED0_YELLOW1;	//next mode
			setTimer1(yellow_time);

			setLedBuffer(yellow_time, yellow_time); // set buffer for led 7 seg

		}

		if(isButton1Pressed() == 1)
		{
			status = MODIFICATION_MODE;
			SCH_Add_Task(FSMModificationModeRun, 0, 0);
		}
		break;

	case RED0_YELLOW1:
		setTrafficRed();
		setTrafficYellow1();

		if(timer3_flag == 1)	//update buffer every second
		{
			updateLedBuffer();
			setTimer3(100);
		}

		//uart
		if(timer2_flag == 1)
		{
			UARTCountdownTrafficTime(1, (led_buffer[0] * 10) + led_buffer[1]);
			UARTCountdownTrafficTime(2, (led_buffer[2] * 10) + led_buffer[3]);
			setTimer2(100);
		}

		if(timer1_flag == 1)
		{
			status = GREEN0_RED1;	//next mode
			setTimer1(green_time);	//set_timer for next mode

			setLedBuffer(green_time, red_time); // set buffer for led 7 seg
		}

		if(isButton1Pressed() == 1)
		{
			status = MODIFICATION_MODE;
			SCH_Add_Task(FSMModificationModeRun, 0, 0);
		}
		break;

	case GREEN0_RED1:
		setTrafficGreen();
		setTrafficRed1();

		if(timer3_flag == 1)
		{
			updateLedBuffer();
			setTimer3(100);

		}

		//uart
		if(timer2_flag == 1)
		{
			UARTCountdownTrafficTime(1, (led_buffer[0] * 10) + led_buffer[1]);
			UARTCountdownTrafficTime(2, (led_buffer[2] * 10) + led_buffer[3]);
			setTimer2(100);
		}

		if(timer1_flag==1)
		{
			status = YELLOW0_RED1;
			setTimer1(yellow_time);

			setLedBuffer(yellow_time, yellow_time);	// set buffer for led 7 seg
		}

		if(isButton1Pressed() == 1)
		{
			status = MODIFICATION_MODE;
			SCH_Add_Task(FSMModificationModeRun, 0, 0);
		}
		break;

	case YELLOW0_RED1:
		setTrafficYellow();
		setTrafficRed1();

		if(timer3_flag == 1)
		{
			updateLedBuffer();
			setTimer3(100);
		}

		//uart
		if(timer2_flag == 1)
		{
			UARTCountdownTrafficTime(1, (led_buffer[0] * 10) + led_buffer[1]);
			UARTCountdownTrafficTime(2, (led_buffer[2] * 10) + led_buffer[3]);
			setTimer2(100);
		}

		if(timer1_flag == 1)
		{
			status = RED0_GREEN1;
			setTimer1(green_time);

			setLedBuffer(red_time, green_time); // set buffer for led 7 seg
		}
		if(isButton1Pressed() == 1)
		{
			status = MODIFICATION_MODE;
			SCH_Add_Task(FSMModificationModeRun, 0, 0);
		}
		break;

	default:
		break;
	}
}

#endif /* SRC_FSMNORMALMODE_C_ */
