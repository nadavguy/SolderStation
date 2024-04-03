/*
 * PushButtonAgent.c
 *
 *  Created on: Jan 30, 2024
 *      Author: user
 */

#include "main.h"

uint32_t lastLEDButtonPressed = 0;
uint32_t lastFANButtonPressed = 0;
uint32_t lastBatteryChargerButtonPressed = 0;

void checkButtons(void)
{
	//LED Button - SW7
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == GPIO_PIN_RESET) && (HAL_GetTick() - lastLEDButtonPressed >= 400) )
	{
		lastLEDButtonPressed = HAL_GetTick();
		if (LEDSwitchState == SwitchOff)
		{
			LEDSwitchState = SwitchOn;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
		}
		else
		{
			LEDSwitchState = SwitchOff;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
		}

	}

	//FAN Button - SW5
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == GPIO_PIN_RESET) && (HAL_GetTick() - lastFANButtonPressed >= 400) )
	{
		lastFANButtonPressed = HAL_GetTick();
		if (FANSwitchState == SwitchOff)
		{
			FANSwitchState = SwitchOn;
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET);
		}
		else
		{
			FANSwitchState = SwitchOff;
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET);
		}
	}

	//Battery Charge Button - SW2
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == GPIO_PIN_RESET) && (HAL_GetTick() - lastBatteryChargerButtonPressed >= 400) )
	{
		lastBatteryChargerButtonPressed = HAL_GetTick();
		if (BatteryChargerSwitchState == SwitchOff)
		{
			BatteryChargerSwitchState = SwitchOn;
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
		}
		else
		{
			BatteryChargerSwitchState = SwitchOff;
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
		}
	}
}
