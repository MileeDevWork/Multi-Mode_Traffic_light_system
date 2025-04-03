/*
 * scheduler.c
 *
 *  Created on: Nov 14, 2024
 *      Author: ACER
 */


#include "scheduler.h"
sTasks SCH_TASKS_G[SCH_MAX_TASKS];
uint8_t index_val = 0;
#define TICK 10
void SCH_INIT(void){
	index_val = 0;
}
void SCH_UPDATE(void){
	for(int i=0;i<index_val;i++){
		if(SCH_TASKS_G[i].Delay > 0 ) SCH_TASKS_G[i].Delay--;
		else {
			SCH_TASKS_G[i].Delay = SCH_TASKS_G[i].Period;
			SCH_TASKS_G[i].RunMe+=1;
		}
	}
}
void SCH_ADD_TASK(void (*pTask)(void), uint32_t Delay, uint32_t Period){
	if(index_val < SCH_MAX_TASKS)
	SCH_TASKS_G[index_val].pTask = pTask;
	SCH_TASKS_G[index_val].Delay = Delay / TICK;
	SCH_TASKS_G[index_val].Period = Period / TICK;
	SCH_TASKS_G[index_val].RunMe = 0;
	SCH_TASKS_G[index_val].TaskID = index_val;
	index_val++;
}
void SCH_DISPATCH_TASK(void){
	for(int i=0;i<index_val;i++){
		if(SCH_TASKS_G[i].RunMe > 0){
			(*SCH_TASKS_G[i].pTask)();
			SCH_TASKS_G[i].RunMe -= 1;
		}
	}
}
//void SCH_DELETE_TASK(index_val){
//SCH_TASKS_G[index_val].pTask = 0x0000;
//SCH_TASKS_G[index_val].Delay = 0;
//SCH_TASKS_G[index_val].Period = 0;
//SCH_TASKS_G[index_val].RunMe = 0;
//}
