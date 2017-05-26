#include <stdio.h>

#include "platform.h"
#include "xparameters.h"
#include "xgpio.h"

#include "FreeRTOS.h"
#include "task.h"

//#include "setup.h"
#include "basic_io.h"

/* Xilinx includes. */
#include "platform.h"
#include "xparameters.h"
#include "xscutimer.h"
#include "xscugic.h"
#include "xil_exception.h"

/* Standard demo includes. */
#include "partest.h"
#include "TimerDemo.h"
#include "QueueOverwrite.h"
#include "EventGroupsDemo.h"
#include "TaskNotify.h"
#include "IntSemTest.h"

#define mainDELAY_LOOP_COUNT (0xffffff)

XScuGic xInterruptController;

static void prvSetupHardware( void );

void vTask1 (void *pvPArameters);
void vTask2 (void *pvPArameters);

int main(void)
{
	prvSetupHardware();

	init_platform();

	xTaskCreate(vTask1, "Task 1", 240, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task 2", 240, NULL, 1, NULL);

	vTaskStartScheduler();

	for( ; ; );

	cleanup_platform();
	return 0;

}

void vTask1(void *pvParameters)
{
	const char *pcTaskName = "Task 1 is running\r\n";
	volatile unsigned long ul;

	for( ;; ){
		vPrintString(pcTaskName);

		XGpio_WriteReg(XPAR_GPIO_0_BASEADDR, XGPIO_DATA_OFFSET, 0x0f);

		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++){
			/*
			 *
			 * */
		}
	}
}

void vTask2(void *pvParameters)
{
	const char *pcTaskName = "Task 2 is running\r\n";
	volatile unsigned long ul;

	for( ;; ){
		vPrintString(pcTaskName);

		XGpio_WriteReg(XPAR_GPIO_0_BASEADDR, XGPIO_DATA_OFFSET, 0x00);

		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++){
			/*
			 *
			 * */
		}
	}
}

static void prvSetupHardware( void )
{
BaseType_t xStatus;
XScuGic_Config *pxGICConfig;

	/* Ensure no interrupts execute while the scheduler is in an inconsistent
	state.  Interrupts are automatically enabled when the scheduler is
	started. */
	portDISABLE_INTERRUPTS();

	/* Obtain the configuration of the GIC. */
	pxGICConfig = XScuGic_LookupConfig( XPAR_SCUGIC_SINGLE_DEVICE_ID );

	/* Sanity check the FreeRTOSConfig.h settings are correct for the
	hardware. */
	configASSERT( pxGICConfig );
	configASSERT( pxGICConfig->CpuBaseAddress == ( configINTERRUPT_CONTROLLER_BASE_ADDRESS + configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET ) );
	configASSERT( pxGICConfig->DistBaseAddress == configINTERRUPT_CONTROLLER_BASE_ADDRESS );

	/* Install a default handler for each GIC interrupt. */
	xStatus = XScuGic_CfgInitialize( &xInterruptController, pxGICConfig, pxGICConfig->CpuBaseAddress );
	configASSERT( xStatus == XST_SUCCESS );
	( void ) xStatus; /* Remove compiler warning if configASSERT() is not defined. */

	/* Initialise the LED port. */
	vParTestInitialise();

	/* The Xilinx projects use a BSP that do not allow the start up code to be
	altered easily.  Therefore the vector table used by FreeRTOS is defined in
	FreeRTOS_asm_vectors.S, which is part of this project.  Switch to use the
	FreeRTOS vector table. */
	vPortInstallFreeRTOSVectorTable();
}
