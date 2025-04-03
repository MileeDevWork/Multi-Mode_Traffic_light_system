/*
 * led_display.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */

#include "main.h"
#include "input_processing.h"
#include "led_display.h"
#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>


// function blink led
// function blink led
void led_red_blink(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)== HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
	}
	else {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
	}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)== HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
		}
		else {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
		}

}
void led_green_blink(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7);
}
void led_yellow_blink(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);


	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
}
// 1: D3 - D4
void mode_light(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
}
void on_red1_led(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);

}
void on_yellow1_led(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);

}
void on_green1_led(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
}
 // 2: D9 - D10
void on_red2_led(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);

}
void on_yellow2_led(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);

}
void on_green2_led(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
}
void off_led1(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
}
void off_led2(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
}

