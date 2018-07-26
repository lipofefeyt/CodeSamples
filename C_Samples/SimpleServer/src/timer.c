/*
 *	@Name:		timer.c
 *
 *	@Author:	lipofefeyt
 *  @Date:		23/07/2018
 */

#include "timer.h"

/* 
 * @Function:	init_timer
 * ----------------------------
 * @Brief:		Initialize the Timer object.
 *  
 */
void init_timer (void) {

	/* Create and initialize the Timer */
	timer = (Timer*)malloc(sizeof(Timer*));

	/* Calls the current time */
	time(&timer->time);

	/* Sets up a timer by default */
	timer->timeinfo = localtime(&timer->time);
}

/* 
 * @Function:	get_time_string
 * ----------------------------
 * @Brief:		Gets the current time, formatted as %dd%MM%yyyy_%hh%mm%ss.
 *  
 */
char* get_time_string (void) {

	/* Result */
	char* output = malloc(16);

	/* Initialize the timer if it has not been yet */
	if (timer == 0) {
		init_timer ();
	}

	/* Output the current year into the result string */
	strftime(output, LOG_DATE_SIZE, "%d/%m/%Y %H:%M:%S", timer->timeinfo);
		
	return output;
}
