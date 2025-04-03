/*
 * fsm_manual.c
 *
 *  Created on: Dec 5, 2024
 *      Author: User
 */

#include "fsm_manual.h"
#include "i2c-lcd.h"
#include "led_display.h"
#include <string.h>
#include <stdio.h>
void show4();
void fsm_manual() {
	if (state == MANUAL) {
		show4();
		switch (manual_state) {

		case MAN_RED_GREEN:
			on_red1_led();
			on_green2_led();
			//__mode1=MAN_GREEN_RED;
			break;
		case MAN_GREEN_RED:
			on_red2_led();
			on_green1_led();
			//__mode1=MAN_RED_GREEN;
			break;
		}
	}
}

void show4() {
	lcd_goto_XY(1, 0);
	lcd_send_string("       ");
	lcd_goto_XY(2, 0);
	lcd_send_string("    ");
	lcd_goto_XY(2, 4);
	lcd_send_string("MANUAL     ");
}
