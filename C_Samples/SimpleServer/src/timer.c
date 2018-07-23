/*
 *	@Name:		timer.c
 *
 *	@Author:	lipofefeyt
 *  @Date:		23/07/2018
 */

#include "timer.h"

/* 
 * Function:	init_timer
 * ----------------------------
 * Initialize the Timer object.
 *  
 */
void init_timer(void) {

	/* Sets up a timer by default */
	timer->seconds = time(NULL);
}
