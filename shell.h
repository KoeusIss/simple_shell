#ifndef SHELL_H
#define SHELL_H

/* Header libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Macros */

#define MAX_TOKEN 512
#define BUFFER_SIZE 1024

/* Structs */

/**
 * struct error - the list of error
 * @code: the error code
 * @txt: the error text
 * Description: this struct allow us to handle the different error
 * of all the project
 * We may call the code, add, move and fix the error in one place.
 */
typedef struct error
{
	int code;
	char *txt;
} err_t;

/* Prototypes */
void error(int);
char **tokenize(char *, char *);
int _strlen(char *);
char *path_concat(char *, char *);
char *_which(char *);

#endif /* SHELL_H */
