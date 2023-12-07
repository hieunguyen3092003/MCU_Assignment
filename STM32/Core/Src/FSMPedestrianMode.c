/*
 * FSMPedestrianMode.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Khoi
 */

#include "FSMPedestrianMode.h"

int PED_PRESSED = 0;

void SetPedDuration()
{
	PED_PRESSED = PED_LIGHT_DURATION * (red_time+green_time+yellow_time);
}

void PedDurationCount()
{
	if(PED_PRESSED > 0)
	{
		PED_PRESSED--;
	}
}

void FSMPedestrianRun()
{
	switch(status)
	{
	case NORMAL_MODE:
		resetInitialState();
		break;
	case RED0_GREEN1:
		if(isButton4Pressed())
		{
			SetPedDuration(); // turn on PED light
		}

		if(PED_PRESSED > 0)
		{
			setPedLightRed();
		}
		else
		{
			setPedLightOff();
		}
		break;
	case RED0_YELLOW1:
		if(isButton4Pressed())
		{
			SetPedDuration(); // turn on PED light
		}

		if(PED_PRESSED > 0)
		{
			setPedLightRed();
		}
		else
		{
			setPedLightOff();
		}
		break;
	case GREEN0_RED1:
		if(isButton4Pressed())
		{
			SetPedDuration(); // turn on PED light
		}

		if(PED_PRESSED > 0)
		{
			setPedLightGreen();
		}
		else
		{
			setPedLightOff();
		}
		break;
	case YELLOW0_RED1:
		if(isButton4Pressed())
		{
			SetPedDuration(); // turn on PED light
		}

		if(PED_PRESSED > 0)
		{
			setPedLightYellow();
		}
		else
		{
			setPedLightOff();
		}
		break;
	default:
		break;
	}
}
