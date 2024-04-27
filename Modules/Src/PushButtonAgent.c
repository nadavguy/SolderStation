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
uint32_t lastStopModeButtonPressed = 0;

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

	//Battery Charge Button - SW6
	if ( (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == GPIO_PIN_RESET) && (HAL_GetTick() - lastBatteryChargerButtonPressed >= 400) )
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

	//Stop Mode Button - SW1
	if ( (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) && (HAL_GetTick() - lastStopModeButtonPressed >= 400) )
	{
		lastStopModeButtonPressed = HAL_GetTick();
		/* Clear the WU FLAG */
		__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
		PWR->CSR1 = PWR_FLAG_WU;
		(void)PWR->CR1;
		DBGMCU->CR = 0;

//		/* clear the RTC Wake UP (WU) flag */
//		__HAL_RTC_WAKEUPTIMER_CLEAR_FLAG(&hrtc, RTC_FLAG_WUTF);

		/* Enable the WAKEUP PIN */
		HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN4_HIGH);
		__DSB();
		__WFI();
		HAL_Delay(3000);
//		HAL_PWR_EnterSTANDBYMode();
		HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFE);
//		for (;;) {
//			__DSB();
//			__WFI();
//		}

	}
}
