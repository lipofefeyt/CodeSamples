/*
 * logger.h
 *
 *  Created on: 20/06/2018
 *	  Author: lipofefeyt
 */


typedef struct Logger {

	FILE* f_pointer;		/* The logger fp */
	char f_name[32];

} Logger;


/* 
 * Function:	main
 * ----------------------------
 * Initialize the Logger object.
 *  
 */
Logger* create_logger(void);
