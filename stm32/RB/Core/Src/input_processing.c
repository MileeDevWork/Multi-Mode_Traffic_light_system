/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */
#include"input_processing.h"
#include "i2c-lcd.h"
#include "fsm_auto.h"
#include "fsm_adjust.h"
#include <string.h>
#include <stdio.h>
int clear_int = 0;
void fsm_for_input_processing(void) {
	getKeyInput();
	//lcd_clear_display();

	switch (state) {
	case IDLE://mode 0
		lcd_goto_XY(1, 0);
						lcd_send_string("       ");
		lcd_goto_XY(2, 0);
				lcd_send_string("  select mode   ");
		mode_light();
		if (button_flag[0] == 1) {
			button_flag[0]=0;
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = AUTO;
		}
		if (button_flag[1] == 1) {
			button_flag[1]=0;
			state = NIGHT;
		}
		if (button_flag[2] == 1) {
			button_flag[2]=0;
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = ADJUST;
		}
		if (button_flag[3] == 1) {
			button_flag[3]=0;
			state = MANUAL;
		}
		break;

	case AUTO://mode 1
		show1();
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;
	}
	break;
	case NIGHT:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;

	}
	break;
	case ADJUST:

	if (button_flag[0] == 1) {
		button_flag[0]=0;
		if (valid){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = IDLE;
		}
	}
	if (button_flag[1] == 1) {
		button_flag[1]=0;
		adj_state = ADJ_MODE;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}
	if (button_flag[2] == 1) {
		button_flag[2]=0;
		adj_state = INCREASE_TIME;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}
	if (button_flag[3] == 1) {
		button_flag[3]=0;
		adj_state = DECREASE_TIME;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}

	break;
	case MANUAL:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;
	}
	if (button_flag[1] == 1) {
			button_flag[1]=0;
			if (flag==0){
				manual_state = MAN_GREEN_RED;
				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
				flag=1;
			}
			else {
				manual_state = MAN_RED_GREEN;
				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
				flag=0;
			}
		}

	break;
}
}
char mode_str[10];

void show(){
	sprintf(mode_str, "%d", state);
	lcd_goto_XY(1, 8);
		lcd_send_string("mode");
		lcd_goto_XY(1, 13);
		lcd_send_string(mode_str);
}



