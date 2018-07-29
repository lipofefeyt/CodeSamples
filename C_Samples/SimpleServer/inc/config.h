/*
 *  @Name:		config.h
 *
 *  @Author:	lipofefeyt
 *  @Date:		29/06/2018
 */

/* Define a Config object */
typedef struct Config {

	char* log_folder;	/* Tha path of the log folder */

} Config;

/* Global Config object */
extern Config* config;
