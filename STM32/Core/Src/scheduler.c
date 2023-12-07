/*
 * scheduler.c
 *
 *  Created on: Dec 7, 2023
 *      Author: bach
 */

#include "scheduler.h"

struct
{
    struct task *top;
} stack_task;

void SCH_Add_Task(void (*pTask)(), uint16_t delay, uint16_t period)
{
    struct task *my_task = (struct task *)malloc(sizeof(struct task));
    my_task->pTask = pTask;
    my_task->counter = delay *FREQ_OF_TIM/1000;
    my_task->period = period;
    my_task->next_task = 0;
    if (stack_task.top == 0)
    {
        stack_task.top = my_task;
        return;
    }
    struct task *pre = stack_task.top;
    struct task *cur = stack_task.top;
    while (cur && my_task->counter >= cur->counter)
    {
        my_task->counter = my_task->counter - cur->counter;
        pre = cur;
        cur = cur->next_task;
    }
    if (pre != cur)
    {
        pre->next_task = my_task;
        my_task->next_task = cur;
    }
    else
    {
        my_task->next_task = cur;
        stack_task.top = my_task;
    }
    if (cur)
        cur->counter -= my_task->counter;
    return;
}

void SCH_Update(void)
{
    if (stack_task.top == 0)
        return;
    if (stack_task.top->counter > 0)
    {
        stack_task.top->counter--;
    }
}

void SCH_Delete_Task(struct task *del_task)
{
    if (del_task == 0)
    {
        return;
    }
    free(del_task);
}

void SCH_Dispatch_Tasks(void)
{
    if (stack_task.top == 0)
        return;
    if (stack_task.top->counter == 0)
    {
        (*stack_task.top->pTask)();
        struct task *temp = stack_task.top;
        stack_task.top = stack_task.top->next_task;
        temp->next_task = 0;
        if (temp->period != 0)
        {
            SCH_Add_Task(temp->pTask, temp->period, temp->period);
        }
        SCH_Delete_Task(temp);
        return;
    }
    return;
}
