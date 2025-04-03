/*
 * fsm_auto.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#include "fsm_auto.h"
#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>
int num1, num2;
void fsm_auto() {
	if (state == AUTO) {

		switch (auto_state) {
		case INIT:
			auto_state = RED_GREEN;
			break;
		case RED_GREEN:
			on_green1_led();
			on_red2_led();
			num1 = green_time - auto_timer;
			num2 = red_time - auto_timer;
			if (auto_timer >= green_time) {
				auto_state = RED_AMBER;
				auto_timer = 0;
			}

			break;
		case RED_AMBER:
			on_yellow1_led();
			on_red2_led();
			num1 = amber_time - auto_timer;
			num2 = red_time - auto_timer - green_time;
			if (auto_timer >= amber_time) {
				auto_state = GREEN_RED;
				auto_timer = 0;
			}

			break;
		case GREEN_RED:
			on_green2_led();
			on_red1_led();
			num1 = red_time - auto_timer;
			num2 = green_time - auto_timer;

			if (auto_timer >= green_time) {
				auto_state = AMBER_RED;
				auto_timer = 0;
			}

			break;
		case AMBER_RED:
			on_yellow2_led();
			on_red1_led();

			num2 = amber_time - auto_timer;
			num1 = red_time - auto_timer - green_time;
			if (auto_timer >= amber_time) {
				auto_state = RED_GREEN;
				auto_timer = 0;
			}

			break;
		}
		auto_timer += 1;
	}
	show1();

}

char num11[10], num22[10];

void show1() {
	lcd_goto_XY(2, 7);
	lcd_send_string("       ");
	lcd_goto_XY(2, 5);
	lcd_send_string(" ");
	sprintf(num11, "%d", num1);
	sprintf(num22, "%d", num2);
//	sprintf(mode_str, "%d", auto_state);
	lcd_goto_XY(1, 0);
	lcd_send_string("road1");
	lcd_goto_XY(1, 6);
	lcd_send_string(num11);
	lcd_goto_XY(2, 0);
	lcd_send_string("road2");
	lcd_goto_XY(2, 6);
	lcd_send_string(num22);
}

