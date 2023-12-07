/*
 * FSMLightModification.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Khoi
 */

#include "FSMLightModification.h"

void FSMLightModification()
{
	switch(status)
	{
	case MODIFY_TIME_RED:
		if(timer4_flag == 1)
		{
			setTimer4(25);
			toggleTrafficRed();
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			red_time++;
			setLedBuffer(red_time, 1);

			//uart
			UARTSendBufferRed(red_time);
		}

		if(isButton3Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_YELLOW;	//next mode
			setTimer4(25);

			setLedBuffer(0, 2);

			//uart
			UARTSendBufferYellow(0);
		}
		break;

	case MODIFY_TIME_YELLOW:
		if(timer4_flag == 1)
		{
			setTimer4(25);
			toggleTrafficYellow();
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			yellow_time++;
			setLedBuffer(yellow_time, 2);

			//uart
			UARTSendBufferYellow(yellow_time);
		}

		if(isButton3Pressed() == 1)
		{
			resetInitialState();

			status = MODIFY_GREEN;	//next mode
			setTimer4(25);

			setLedBuffer(0, 3);

			//uart
			UARTSendBufferGreen(0);
		}
		break;

	case MODIFY_TIME_GREEN:
		if(timer4_flag == 1)
		{
			setTimer4(25);

			toggleTrafficGreen();
		}

		if(isButton2Pressed() == 1)
		{
			resetInitialState();

			green_time++;
			setLedBuffer(green_time, 3);

			//uart
			UARTSendBufferGreen(green_time);
		}

		if(isButton3Pressed() == 1)
		{
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
		break;
	default:
		break;
	}
}
