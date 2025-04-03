/*
 * led_display.h
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

void mode_light();

void led_red_blink();
void led_green_blink();
void led_yellow_blink();

void on_red1_led();
void on_yellow1_led();
void on_green1_led();
 // 2: D9 - D10
void on_red2_led();
void on_yellow2_led();
void on_green2_led();
void off_led1();
void off_led2();



#endif /* INC_LED_DISPLAY_H_ */
