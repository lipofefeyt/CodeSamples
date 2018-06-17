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

/* 
 * Function:	main
 * ----------------------------
 * Main function to run a client and make it connect to a server running on the 
 * address passed as argument.
 *  
 */
int main(int argc, char *argv[]) {

	/* Some useful variables */
	int sockfd = 0, bytes_read = 0;
	char recvBuff[1024];

	/* Connection variables */
	struct sockaddr_in serv_addr; 

	/* Check the arguments */
	if(argc != 2)
	{
		printf("\n Usage: %s <ip of server> \n",argv[0]);
		return 1;
	} 

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
	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
	{
		printf("\n inet_pton error occured\n");
		return 1;
	} 

	/* Connect to the socket */
	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
	   printf("\n Error : Connect Failed \n");
	   return 1;
	} 

	/* Read while there's something to read */
	while((bytes_read = read(sockfd, recvBuff, sizeof(recvBuff) - 1)) > 0) {

		/* Put the string terminator */
		recvBuff[bytes_read] = 0;

		if(fputs(recvBuff, stdout) == EOF)
		{
			printf("\n Error : Function fputs error\n");
		}
	} 

	/* If read returns negative there's a problem */
	if(bytes_read < 0)
	{
		printf("\n Read error \n");
	} 

	return 0;
}
