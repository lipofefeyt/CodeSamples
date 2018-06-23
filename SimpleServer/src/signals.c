/*
 * signals.c
 *
 *  Created on: 23/06/2018
 *	  Author: lipofefeyt
 */

#include "logger.h"
#include "signals.h"

/* Link with the global Logger */
Logger* logger;

/* 
 * Function:	handle_sigint
 * ----------------------------
 * Initialize the Logger object.
 *  
 */
void handle_sigint() {

	if(logger->f_pointer != NULL) {
		fclose(logger->f_pointer);
	}

	printf("SIGINT!\n");

	exit(-1);
}
