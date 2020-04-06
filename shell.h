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
#include <stdarg.h>

/* Macros */

#define MAX_TOKEN 64
#define BUFFER_SIZE 256

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
char **tokenize(char *line, char *delimiter);
int _strlen(char *str);
char *_strcat(char *first, char *second);
char *_which(char *command);
void *_realloc(void *ptr, unsigned int old, unsigned int new);
int execute_cmd(char *cmd, char **args);
void *fill_an_array(void *a, int el, unsigned int len);

#endif /* SHELL_H */
