/*
 * global.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */


#include "global.h"


int state=IDLE;
int flag=0;
int auto_state=INIT;
int adj_state=ADJ_INIT;
int manual_state=MANUAL_INIT;

int auto_timer = 0, led_catch_timer=0;
int red_time=5, amber_time = 2, green_time = 3;
int valid = 1;

int __mode = MODE_RED;
int __mode1=MAN_RED_GREEN;
