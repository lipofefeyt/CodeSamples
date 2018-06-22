/*
 * logger.c
 *
 *  Created on: 20/06/2018
 *	  Author: lipofefeyt
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include "logger.h"

/* Global Logger object */
extern Logger* logger;

/* 
 * Function:	main
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
