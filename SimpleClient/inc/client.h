/*
 * client.h
 *
 *  Created on: 18/06/2018
 *	  Author: lipofefeyt
 */

/* Define type client */
typedef struct Client {

	uint8_t c_id;		/* Client's ID */
	char	c_name[16]; /* Client's Name */

} Client;

/* Initializes a Client type */
void init_client(Client* client);
