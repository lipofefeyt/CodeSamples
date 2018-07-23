/*
 * client.c
 *
 *  Created on: 03/06/2018
 *	  Author: lipofefeyt
 */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#include "client.h"

/* 
 * Function:	main
 * ----------------------------
 * Main function to run a client and make it connect to a server running on a 
 * given address.
 *  
 */
int main(int argc, char *argv[]) {

	/* Declare a client */
	Client client;

	/* Some useful variables */
	int sockfd = 0, bytes_read = 0;
	char recvBuff[1024];

  	/* FIXME: We're using localhost for now */
	char address[16] = "127.0.0.1";

	/* Connection variables */
	struct sockaddr_in serv_addr; 

	/* Initialize the client */
	init_client(&client);
	
	/* FIXME: We'll be using a configuration file soon */
	/* Read client's data from stdin */
	printf("Welcome!\n\nPlease enter your name and press ENTER: ");
	scanf("%s",client.c_name);

	printf("\n=== Client's Data ===\n");
	printf("ID:	%d\n", (rand() % 20) * getpid());
	printf("Name:	%s\n\n", client.c_name);

	/* Create the socket for connection */
	memset(recvBuff, '0',sizeof(recvBuff));
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Error : Could not create socket \n");
		return 1;
	} 

	/* Allocate some memory and store the address */
	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000); 

	/* Convert the network address */
	if(inet_pton(AF_INET, address, &serv_addr.sin_addr)<=0)
	{
		printf("\nError: Function 'inet_pton' error ocurred\n");
		return 1;
	} 

	/* Connect to the socket */
	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
	   printf("\nError: Connect Failed \n");
	   return 1;
	} 

	/* Read while there's something to read */
	while((bytes_read = read(sockfd, recvBuff, sizeof(recvBuff) - 1)) > 0) {

		/* Put the string terminator */
		recvBuff[bytes_read] = 0;

		/* If we reached the EOF */
		if(fputs(recvBuff, stdout) == EOF)
		{
			printf("\n Error: Function 'fputs' error ocurred\n");
		}
	} 

	/* If read returns negative there's a problem */
	if(bytes_read < 0)
	{
		printf("\nError: Number of bytes read -> %d\n", bytes_read);
	} 

	return 0;
}

/* Initializes a Client type */
void init_client(Client* client) {

	/* Allocate memory for new client */
	client = malloc(sizeof(Client*));
}
