/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define PED_BUTTON_Pin GPIO_PIN_0
#define PED_BUTTON_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_1
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_5
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_0
#define BUTTON3_GPIO_Port GPIOB
#define PED_LIGHT1_Pin GPIO_PIN_10
#define PED_LIGHT1_GPIO_Port GPIOB
#define PED_LIGHT2_Pin GPIO_PIN_8
#define PED_LIGHT2_GPIO_Port GPIOA
#define LIGHT2_Pin GPIO_PIN_10
#define LIGHT2_GPIO_Port GPIOA
#define LIGHT3_Pin GPIO_PIN_3
#define LIGHT3_GPIO_Port GPIOB
#define LIGHT4_Pin GPIO_PIN_4
#define LIGHT4_GPIO_Port GPIOB
#define LIGHT5_Pin GPIO_PIN_5
#define LIGHT5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
