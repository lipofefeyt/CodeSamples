/*
 * server.h
 *
 *  Created on: 20/06/2018
 *	  Author: lipofefeyt
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

/* 
 * Function:	main
 * ----------------------------
 * Main function to run a server and make it listen to all the available 
 * interfaces (INADDR_ANY).
 *  
 */
int main(int argc, char *argv[]);
