#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */

/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 *
 * Description: A structure contains all the variables needed to manage
 * the program, memory and accessability
 */
typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;
/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 *
 * Description: this struct made to manage builtins cmd
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;
/* ----------Process prototype------------*/
int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int process_cmd(sh_t *);

/* ----------String prototype------------*/
char *_strdup(char *str);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);

/* ----------More String prototype-------*/
char *_strcpy(char *dest, char *source);

/* ----------Memory prototype------------*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char byt, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int free_data(sh_t *);

/* ----------Tools prototype-------------*/
void *fill_an_array(void *a, int el, unsigned int len);
void signal_handler(int signo);
char *_getenv(char *path_name);
void index_cmd(sh_t *data);
void array_rev(char *arr, int len);

/* ----------More tools prototype--------*/
char *_itoa(unsigned int n);
int intlen(int num);
int _atoi(char *c);
int print_error(sh_t *data);
int write_history(sh_t *data);
int _isalpha(int c);

/* -------------Builtins-----------------*/
int abort_prg(sh_t *data);
int change_dir(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);
int check_builtin(sh_t *data);

/* -------------Parse-----------------*/
int is_path_form(sh_t *data);
void is_short_form(sh_t *data);
int is_builtin(sh_t *data);

#endif /* SHELL_H */
