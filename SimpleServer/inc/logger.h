/*
 *	@Name:		logger.h
 *
 *	@Author:	lipofefeyt
 *  @Date:		20/06/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

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
 * Function:	delete_logger
 * ----------------------------
 * Delete the Logger object.
 *  
 */
void delete_logger(void);

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
