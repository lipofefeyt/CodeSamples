/*
 *  @Name:		timer.h
 *
 *  @Author:	lipofefeyt
 *  @Date:		23/07/2018
 */

#include <time.h>
#include <stdlib.h>

#include "globals.h"

/* Define a Timer object */
typedef struct Timer {

	time_t time;			/* To store seconds since 01/01/1970 */
	struct tm* timeinfo;	/* Information on the loca time */

} Timer;

/* Global Timer object */
extern Timer* timer;

/* 
 * @Function:	init_timer
 * ----------------------------
 * @Brief:		Initialize the Timer object.
 *  
 */
void init_timer (void);

/* 
 * @Function:	get_time_string
 * ----------------------------
 * @Brief:		Gets the current time, formatted as %dd%MM%yyyy_%hh%mm%ss.
 *  
 */
char* get_time_string (void);
