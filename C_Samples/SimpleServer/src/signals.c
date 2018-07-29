/*
 *  @Name:		signals.c
 *
 *  @Author:	lipofefeyt
 *  @Date:		23/06/2018
 */

#include "logger.h"
#include "signals.h"

/* Link with the global Logger */
Logger* logger;

/* 
 * @Function:	handle_sigint
 * ----------------------------
 * @Brief:		Initialize the Logger object.
 * 
 */
void handle_sigint () {

	if(logger->f_pointer != NULL) {
		fclose(logger->f_pointer);
	}

	printf("Signal SIGINT handled. Program will now exit...\n");

	/* Terminate the program */
	exit(-1);
}
