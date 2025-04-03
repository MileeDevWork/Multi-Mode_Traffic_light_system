/*
 * button.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define NUM_BUT 5
extern int button_flag[NUM_BUT];

void getKeyInput();

#endif /* INC_BUTTON_H_ */
