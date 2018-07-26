/*
 *	@Name:		signals.h
 *
 *	@Author:	lipofefeyt
 *  @Date:		23/06/2018
 */

#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */

#include <stdio.h>
#include <stdlib.h>

/* 
 * @Function:	handle_sigint
 * ----------------------------
 * @Brief:		Initialize the Logger object.
 * 
 */
void handle_sigint ();
