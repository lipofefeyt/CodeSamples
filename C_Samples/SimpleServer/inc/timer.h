/*
 *	@Name:		timer.h
 *
 *	@Author:	lipofefeyt
 *	@Date:		23/07/2018
 */

#include <time.h>

/* Define a Timer object */
typedef struct Timer {

	time_t seconds;		/* To store seconds since 01/01/1970 */

} Timer;

/* Global Timer object */
extern Timer* timer;

/* 
 * Function:	init_timer
 * ----------------------------
 * Initialize the Timer object.
 *  
 */
void init_timer(void);
