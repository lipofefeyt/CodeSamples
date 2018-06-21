/*
 * server.c
 *
 *  Created on: 03/06/2018
 *	  Author: lipofefeyt
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include "server.h"

/* 
 * Function:	main
 * ----------------------------
 * Main function to run a server and make it listen to all the available 
 * interfaces (INADDR_ANY).
 *  
 */
int main(int argc, char *argv[]) {

	/* Some useful variables */
	int listenfd = 0, connfd = 0;
	int num_clients = 0;
	char sendBuff[1025];

	/* Connection variables */
	struct sockaddr_in serv_addr;
	time_t ticks;

	/* Initialize the socket descriptor */
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	/* Fill the server's address completely */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	/* Bind the socket to the filled address */
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	/* So start listening max to 10 connections */
	listen(listenfd, 10);

	/* Wait for clients to connect */
	while(1)
	{
		printf("Listening.. \n");	

		/* Accept clients */
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

		/* Count number of clients */
		if(connfd > 0){
			num_clients++;
			printf("Client number %d\n", num_clients);
		}

		/* Tell them the time */
		ticks = time(NULL);
		sprintf(sendBuff, "%.24s\r\n", ctime(&ticks));
		write(connfd, sendBuff, strlen(sendBuff));

		/* Close the connection and wait 1sec */
		close(connfd);
		sleep(1);
	}
	
	return 0;	
}


