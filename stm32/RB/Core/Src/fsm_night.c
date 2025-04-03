/*
 * fsm_night.c
 *
 *  Created on: Dec 5, 2024
 *      Author: User
 */

#include "fsm_night.h"
#include "i2c-lcd.h"
#include "led_display.h"
#include <string.h>
#include <stdio.h>

void show2();
void fsm_night() {
	if (state == NIGHT) {
		led_yellow_blink();
		show2();
	}
}

void show2() {
	lcd_goto_XY(1, 0);
	lcd_send_string("       ");
	lcd_goto_XY(2, 0);
	lcd_send_string("    ");
	lcd_goto_XY(2, 4);
	lcd_send_string("NIGHT");
}
