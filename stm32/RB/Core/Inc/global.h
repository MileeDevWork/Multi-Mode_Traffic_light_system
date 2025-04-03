/*
 * global.h
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "led_display.h"


#define IDLE 0
#define AUTO 1
#define ADJUST 3
#define NIGHT 2
#define MANUAL 4


#define ADJ_MODE 10
#define INCREASE_TIME 11
#define DECREASE_TIME 12

#define INIT 20
#define RED_GREEN 21
#define RED_AMBER 22
#define GREEN_RED 23
#define AMBER_RED 24

#define ADJ_INIT 29
#define MODE_RED 30
#define MODE_GREEN 31
#define MODE_AMBER 32

#define MANUAL_INIT 33
#define MAN_RED_GREEN 34
#define MAN_GREEN_RED 35

extern int state;
extern int adj_state;
extern int auto_state;
extern int manual_state;

extern int flag;
extern int valid;
extern int __mode;
extern int __mode1;
extern int red_time, amber_time, green_time;
extern int auto_timer,man_timer,error_timer;

#endif /* INC_GLOBAL_H_ */
