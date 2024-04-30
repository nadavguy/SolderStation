/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "MenuHelper.h"
#include "FrameHelper.h"
#include "ItemHelper.h"
#include "PopupHelper.h"
#include "fonts.h"
#include "ScreenAgent.h"
#include "GeneralMath.h"
#include "PushButtonAgent.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum sSwitchState {SwitchOff, SwitchOn} tSwitchState;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPIO_Input_LED_Pin GPIO_PIN_3
#define GPIO_Input_LED_GPIO_Port GPIOE
#define GPIO_Input_Right_Pin GPIO_PIN_4
#define GPIO_Input_Right_GPIO_Port GPIOE
#define GPIO_Input_Arm_Pin GPIO_PIN_5
#define GPIO_Input_Arm_GPIO_Port GPIOE
#define ADC1_IN1_CurrentMeasurement_Pin GPIO_PIN_1
#define ADC1_IN1_CurrentMeasurement_GPIO_Port GPIOA
#define SPI_SCK_LCD_Pin GPIO_PIN_5
#define SPI_SCK_LCD_GPIO_Port GPIOA
#define TIM3_CH1_PWM_LED_FET_Pin GPIO_PIN_6
#define TIM3_CH1_PWM_LED_FET_GPIO_Port GPIOA
#define SPI_MOSI_LCD_Pin GPIO_PIN_7
#define SPI_MOSI_LCD_GPIO_Port GPIOA
#define GPIO_Output_LCD_DC_Pin GPIO_PIN_4
#define GPIO_Output_LCD_DC_GPIO_Port GPIOC
#define GPIO_Output_LCD_Reset_Pin GPIO_PIN_5
#define GPIO_Output_LCD_Reset_GPIO_Port GPIOC
#define TIM3_CH3_LCD_Backlight_Pin GPIO_PIN_0
#define TIM3_CH3_LCD_Backlight_GPIO_Port GPIOB
#define GPIO_Input_Trigger_Pin GPIO_PIN_9
#define GPIO_Input_Trigger_GPIO_Port GPIOE
#define GPIO_Output_LCD_CS_Pin GPIO_PIN_6
#define GPIO_Output_LCD_CS_GPIO_Port GPIOC
#define GPIO_Input_ChargeDetect_Pin GPIO_PIN_9
#define GPIO_Input_ChargeDetect_GPIO_Port GPIOA
#define GPIO_Input_Up_Pin GPIO_PIN_3
#define GPIO_Input_Up_GPIO_Port GPIOD
#define GPIO_Input_Down_Pin GPIO_PIN_4
#define GPIO_Input_Down_GPIO_Port GPIOD
#define GPIO_Input_ChargeBattery_SW2_Pin GPIO_PIN_7
#define GPIO_Input_ChargeBattery_SW2_GPIO_Port GPIOD
#define GPIO_Output_LED_Pin GPIO_PIN_4
#define GPIO_Output_LED_GPIO_Port GPIOB
#define GPIO_Output_FAN_Pin GPIO_PIN_0
#define GPIO_Output_FAN_GPIO_Port GPIOE
#define GPIO_Output_ChargeEN__Pin GPIO_PIN_1
#define GPIO_Output_ChargeEN__GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */
extern float versionID;
extern float buildID;

extern uint8_t ampReadingArray[100];
extern uint8_t ampReadingArrayFiltered[100];

extern uint16_t milliAmpsForDisplay;
extern uint16_t milliAmpsForDisplayFiltered;

extern bool isBatteryCharging;

extern tCURSOR_DATA currentCursorPosition;
extern tSwitchState LEDSwitchState;
extern tSwitchState FANSwitchState;
extern tSwitchState BatteryChargerSwitchState;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
