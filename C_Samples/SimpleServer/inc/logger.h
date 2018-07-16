/*
 * logger.h
 *
 *  Created on: 20/06/2018
 *	  Author: lipofefeyt
 */

#include <stdio.h>

/* Define a Logger object */
typedef struct Logger {

	FILE* f_pointer;		/* The logger fp */
	char f_name[32];

} Logger;

/* Global Logger object */
extern Logger* logger;

/* 
 * Function:	create_logger
 * ----------------------------
 * Initialize the Logger object.
 *  
 */
void create_logger(void);

/* 
 * Function:	log_msg
 * ----------------------------
 * Logs the message to thw log file
 * 
 * Params:
 * @msg The message to be written
 *  
 */
int log_msg(char* msg);
