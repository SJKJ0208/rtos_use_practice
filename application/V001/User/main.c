/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/ 
/* FreeRTOS头文件 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* 开发板硬件bsp头文件 */
#include "bsp_exti.h"

/* 标准库头文件 */
#include <string.h>
#include <stdarg.h>


#include "fk_soft_typedef.h"
#include "drv_opt.h"
#include "task_manager.h"

/**************************** 任务句柄 ********************************/

/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void BSP_Init(void);/* 用于初始化板载相关资源 */

int main(void)
{	
	BSP_Init();  	
	do_create_start_task();
	

	while(1);/* 正常不会执行到这里 */    
}

/***********************************************************************
  * @ 函数名  ： BSP_Init
  * @ 功能说明： 板级外设初始化，所有板子上的初始化均可放在这个函数里面
  * @ 参数    ：   
  * @ 返回值  ： 无
  *********************************************************************/
static void BSP_Init(void)
{
	/*
	 * STM32中断优先级分组为4，即4bit都用来表示抢占优先级，范围为：0~15
	 * 优先级分组只需要分组一次即可，以后如果有其他的任务需要用到中断，
	 * 都统一用这个优先级分组，千万不要再分组，切忌。
	 */
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	/* 串口初始化	*/
	init_drv_debug_usart_before_os_run();
  
	
}

/********************************END OF FILE****************************/
