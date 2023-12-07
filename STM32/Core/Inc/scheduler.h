/*
 * scheduler.h
 *
 *  Created on: Dec 8, 2023
 *      Author: bach
 */

#ifndef INC_MY_SCHEDULER_H_
#define INC_MY_SCHEDULER_H_


#include <stdint.h> // now we able to use unsigned int 32 bit
#include<stdlib.h>


#define SCH_MAX_TASKS	40
#define FREQ_OF_TIM		100
/*
@brief: pTask - pointer pointing to the function that will run
		counter - the amount of remaining time or the time after the previous task
		period - the amount of cycle time to run task
		next_task - pointer pointing to the next task
*/
struct task
{
    void (*pTask)();
    uint16_t counter;
    uint16_t period;
    struct task *next_task;
};

void SCH_Add_Task(void (*pTask)(), uint16_t delay, uint16_t period); // giống như set 1 cái timer

void SCH_Update(void); // giống với timer run (được gọi trong ISR

void SCH_Dispatch_Tasks(void); // giống với kiểm tra flag (được gọi trong while 1)


#endif /* INC_SCHEDULER_H_ */
