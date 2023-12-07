/*
 * FSMModificationMode.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Khoi
 */
#include "FSMModificationMode.h"


void FSMModificationModeRun()
{
	switch(status)
	{
	case MODIFICATION_MODE:
		resetInitialState();	// reset all all the varialbles thats affect FSMModificationModeRun

		UARTSendMode(2);

		status = MODIFY_RED;	// next mode

		//led blinky for 2hz
		setTimer4(25);

		// initial setting led 7 seg
		setLedBuffer(0, 1);

		//uart
		UARTSendMode(2);
		UARTSendBufferRed(0);

		break;

	case MODIFY_RED:

		if(timer4_flag == 1)
		{
			setTimer4(25);
			toggleTrafficRed();
		}

		if(isButton1Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_YELLOW;	//next mode
			setTimer4(25);

			// initial setting led 7 seg
			setLedBuffer(0, 2);

			//uart
			UARTSendBufferYellow(0);
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_TIME_RED; //next mode
			setTimer4(25);

			red_time = 1;
			setLedBuffer(red_time, 1);

			//uart
			UARTSendBufferRed(red_time);
		}
		break;

	case MODIFY_YELLOW:

		if(timer4_flag == 1)
		{
			setTimer4(25);

			toggleTrafficYellow();
		}

		if(isButton1Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_GREEN;
			setTimer4(25);

			setLedBuffer(0, 3);

			//uart
			UARTSendBufferGreen(0);
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_TIME_YELLOW;
			setTimer4(25);

			yellow_time = 1;
			setLedBuffer(yellow_time, 2);

			//uart
			UARTSendBufferYellow(yellow_time);

		}
		break;

	case MODIFY_GREEN:

		if(timer4_flag == 1)
		{
			setTimer4(25);

			toggleTrafficGreen();
		}

		if(isButton1Pressed() == 1)
		{
			resetInitialState();
			if(red_time == green_time+yellow_time)
			{
				status = NORMAL_MODE;
			}
			else
			{
				if(red_time > green_time+yellow_time)
				{
					green_time = red_time - yellow_time;
					status = NORMAL_MODE;
				}
				else
				{
					red_time = green_time + yellow_time;
					status = NORMAL_MODE;
				}
			}
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_TIME_GREEN;
			green_time = 1;
			setLedBuffer(green_time, 3);

			//uart
			UARTSendBufferGreen(green_time);
		}
		break;

	default:
		break;
	}
}
