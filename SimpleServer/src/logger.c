/*
 *	@Name:		logger.c
 *
 *	@Author:	lipofefeyt
 *  @Date:		20/06/2018
 */

#include "logger.h"

/* 
 * Function:	create_logger
 * ----------------------------
 * Initialize the Logger object.
 *  
 */
void create_logger(void) {

	/* Create and initialize the Logger */
	logger = (Logger*)malloc(sizeof(Logger*));
	memcpy(logger->f_name, "Test.log", 9);

	/* Open the log file */
	logger->f_pointer = fopen(logger->f_name ,"w+");
}

/* 
 * Function:	delete_logger
 * ----------------------------
 * Delete the Logger object.
 *  
 */
void delete_logger(void) {

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
 * Function:	log_msg
 * ----------------------------
 * Logs the message to thw log file
 * 
 * Params:
 * @msg The message to be written
 *  
 */
int log_msg(char* msg) {

	/* Write to the file */
	fprintf(logger->f_pointer, msg);

	return 1;
}
