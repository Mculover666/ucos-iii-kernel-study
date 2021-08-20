#include "os.h"
#include <stdio.h>

static OS_TCB  task1;
static CPU_STK task1_stack[512];

static OS_TCB  task2;
static CPU_STK task2_stack[512];

static int task1_entry(void *args)
{
    OS_ERR  err;
    
	(void)args;
		  
	while(1)
	{
        printf("task1 is running...\r\n");
	    OSTimeDly(1000, OS_OPT_TIME_DLY, &err);		
	}   

}

static int task2_entry(void *args)
{
    OS_ERR  err;
    
	(void)args;
		  
	while(1)
	{
        printf("task2 is running...\r\n");
	    OSTimeDly(1000, OS_OPT_TIME_DLY, &err);		
	}   

}

int application_entry(void)
{
    OS_ERR  err;
    
    OSTaskCreate(&task1, "task1", (OS_TASK_PTR)task1_entry, NULL, 2, 
                  task1_stack, 512, 512, 0, 0, NULL,
                  OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR, &err);

    OSTaskCreate(&task2, "task2", (OS_TASK_PTR)task2_entry, NULL, 3, 
                  task2_stack, 512, 512, 0, 0, NULL,
                  OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR, &err);
    
    return 0;
}


