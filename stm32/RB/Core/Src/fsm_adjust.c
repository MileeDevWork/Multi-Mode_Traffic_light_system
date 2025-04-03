/*
 * fsm_adjust.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */

#include "fsm_adjust.h"
#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>
void showok(){
	lcd_goto_XY(1, 0);
			lcd_send_string("VALID    ");
}
void showerror(){
	lcd_goto_XY(1, 0);
			lcd_send_string("WARNING ");
}
void error_led() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
}
void no_error_led() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
}
int mode=0;
void show3();
void fsm_adjust()
{

	if (state == ADJUST) {
show3();
		switch (adj_state) {
		case ADJ_INIT:
			if (red_time != green_time + amber_time) {
				error_led();
				showerror();
				valid = 0;
			} else {
				no_error_led();
				showok();
				valid = 1;
			}
			break;
		case ADJ_MODE:
			switch (__mode) {
			case MODE_RED:
				on_green1_led();
				on_green2_led();
				__mode = MODE_GREEN;
				break;
			case MODE_GREEN:
				on_yellow1_led();
				on_yellow2_led();
				__mode = MODE_AMBER;
				break;
			case MODE_AMBER:
				on_red1_led();
				on_red2_led();
				__mode = MODE_RED;
				break;
			}
			adj_state = ADJ_INIT;
			break;
		case INCREASE_TIME:
			if (__mode == MODE_RED) {
				red_time++;
			} else if (__mode == MODE_GREEN) {
				green_time++;
			} else if (__mode == MODE_AMBER) {
				amber_time++;
			}
			adj_state = ADJ_INIT;
			break;
		case DECREASE_TIME:
			if (__mode == MODE_RED)
				red_time--;
			else if (__mode == MODE_GREEN)
				green_time--;
			else if (__mode == MODE_AMBER)
				amber_time--;
			adj_state = ADJ_INIT;
			break;
		}

	}
}
char r[10], g[10], y[10];

void show3(){

	sprintf(r, "%d", red_time);
	sprintf(g, "%d", green_time);
	sprintf(y, "%d", amber_time);
//	sprintf(mode_str, "%d", auto_state);
	lcd_goto_XY(2, 0);
	lcd_send_string("R:");
	lcd_goto_XY(2, 3);
	lcd_send_string("   ");
	lcd_goto_XY(2, 2);
	lcd_send_string(r);

	lcd_goto_XY(2, 6);
	lcd_send_string("Y:");
	lcd_goto_XY(2, 9);
	lcd_send_string(" ");
	lcd_goto_XY(2, 8);
	lcd_send_string(y);

	lcd_goto_XY(2, 12);
	lcd_send_string("G:");
	lcd_goto_XY(2, 15);
	lcd_send_string(" ");
	lcd_goto_XY(2, 14);
	lcd_send_string(g);

}
