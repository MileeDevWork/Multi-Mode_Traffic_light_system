/*
 * scheduler.h
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void(*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTasks;

#define SCH_MAX_TASKS 10

void SCH_INIT(void);
void SCH_UPDATE(void);
void SCH_ADD_TASK(void (*pTask)(void), uint32_t Delay, uint32_t Period);
void SCH_DISPATCH_TASK(void);
//void SCH_DELETE_TASK(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
