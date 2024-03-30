/*
 * PushButtonAgent.c
 *
 *  Created on: Jan 30, 2024
 *      Author: user
 */

#include "main.h"

uint32_t lastLEDButtonPressed = 0;
uint32_t lastFANButtonPressed = 0;

int32_t setPointValue[2] = {25, 25};

void checkButtons(void)
{
	//LED Button - SW7
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == GPIO_PIN_RESET) && (HAL_GetTick() - lastLEDButtonPressed >= 400) )
	{
		lastLEDButtonPressed = HAL_GetTick();
		if (LEDSwitchState == SwitchOff)
		{
			LEDSwitchState = SwitchOn;
		}
		else
		{
			LEDSwitchState = SwitchOff;
		}

	}

	//FAN Button - SW5
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == GPIO_PIN_RESET) && (HAL_GetTick() - lastFANButtonPressed >= 400) )
	{
		lastFANButtonPressed = HAL_GetTick();
		if (FANSwitchState == SwitchOff)
		{
			FANSwitchState = SwitchOn;
		}
		else
		{
			FANSwitchState = SwitchOff;
		}
	}
}
