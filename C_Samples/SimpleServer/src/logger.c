/*
 *	@Name:		logger.c
 *
 *	@Author:	lipofefeyt
 *  @Date:		20/06/2018
 */

#include "logger.h"
#include "timer.h"

/* 
 * @Function:	create_logger
 * ----------------------------
 * @Brief:		Initialize the Logger object.
 *  
 */
void create_logger (void) {

	/* Create and initialize the Logger */
	logger = (Logger*)malloc(sizeof(Logger*));
	memcpy(logger->f_name, "Test.log", 9);

	/* Open the log file */
	logger->f_pointer = fopen(logger->f_name ,"w+");
}

/* 
 * @Function:	delete_logger
 * ----------------------------
 * @Brief:		Delete the Logger object.
 *  
 */
void delete_logger (void) {

	/* Check if it's not NULL */
	if(logger != NULL) { 

		/* Close any open file if possible */
		if(logger->f_pointer != NULL) {
			fclose(logger->f_pointer);
		}

		/* Deallocate all memory */
		free(logger);
	}
}

/* 
 * @Function:	log_msg
 * ----------------------------
 * @Brief:		Logs the message to thw log file
 * 
 * @Params:
 * msg:			The message to be logged
 *  
 */
int log_msg (char* msg) {

	/* The output */
	char* log_msg = malloc(256);

	/* Log time with message */
	sprintf(log_msg, "%s | %s", get_time_string(), msg);

	/* Write to the file */
	return fprintf(logger->f_pointer, log_msg);
}
