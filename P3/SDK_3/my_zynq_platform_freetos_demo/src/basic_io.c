/*
 * basic_io.c
 *
 *  Created on: May 3, 2017
 *      Author: root
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#define ioMAX_MSG_LEN	( 50 )
static char cBuffer[ ioMAX_MSG_LEN ];

void vPrintString( const char *pcString ){
	vTaskSuspendAll();
	{
		sprintf( cBuffer, "%s", pcString );
		print( cBuffer );
	}
	xTaskResumeAll();
}

void vPrintStringAndNumber( const char *pcString, unsigned long ulValue ){
	vTaskSuspendAll();
	{
		sprintf( cBuffer, "%s %ul\n", pcString, ulValue );
		print( cBuffer );
	}
	xTaskResumeAll();
}
