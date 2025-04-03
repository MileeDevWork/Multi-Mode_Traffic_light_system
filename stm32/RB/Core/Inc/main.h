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
#define BUTTON_Pin GPIO_PIN_13
#define BUTTON_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_4
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_10
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_8
#define BUTTON_4_GPIO_Port GPIOA
#define BUTTON_4_Pin GPIO_PIN_9
#define BUTTON_3_GPIO_Port GPIOA
#define red1_Pin GPIO_PIN_3
#define red1_GPIO_Port GPIOB
#define yellow1_Pin GPIO_PIN_5
#define yellow1_GPIO_Port GPIOB
#define green1_Pin GPIO_PIN_12
#define green1_GPIO_Port GPIOB
#define red2_Pin GPIO_PIN_7
#define red2_GPIO_Port GPIOC
#define yellow2_Pin GPIO_PIN_6
#define yellow2_GPIO_Port GPIOB
#define green2_Pin GPIO_PIN_15
#define green2_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_3
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_4
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_5
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_6
#define EN4_GPIO_Port GPIOB
#define mode_Pin GPIO_PIN_7
#define mode_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
