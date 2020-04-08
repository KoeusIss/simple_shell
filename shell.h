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

/* Global variables */



/* Structs */

/**
 * struct built_in - the struct of built_in function
 * @name: the name of the built_in function
 * Description: this struct allow us to handle the different error
 * of all the project
 * We may call the code, add, move and fix the error in one place.
 */
typedef struct built_in
{
	char *name;
	int (*f)(char *);
} blt_in;

/* Launcher */

int execute_cmd(char *cmd, char **args);

/* Parser */

char *_which(char *command);

/* Lexical analyzer */

char **tokenize(char *line, char *delimiter);

/* Built-ins */

int quit(void);

/* Tools */

void *_realloc(void *ptr, unsigned int old, unsigned int new);
void *fill_an_array(void *a, int el, unsigned int len);

/* Strings */

int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *first, char *second);
char *_strdup(char *str);

/* Error */

void error(int);

#endif /* SHELL_H */
