#ifndef SHELL_H
#define SHELL_H

/* Header file */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Macros */
#define BUF_SIZE 256

/* Global variable */
extern char **environ;

/* Prototypes */
char *read_line(char *prompt);
char **parse_line(char *line);
int execute_cmd(char **cmd);
void *fill_array(void *arr, int el, size_t len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_which(char *cmd);

/* builtins */
int cd(char *path);

/* String */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *str, char c);
char *_strdup(char *str);

#endif /* SHELL_H */
