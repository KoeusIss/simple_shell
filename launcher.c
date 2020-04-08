/**
 * Holberton School Project - Simple Shell
 * Author: KoeusIss
 *
 * Launcher - a file to handle the execute, and system call functions.
 * a launcher is a pltform to working with command in final lexical form
 * helps to seperate the execution and process call function
 */
#include "shell.h"

/**
 * execute_cmd - Executes command 
 * @av: Argument vector
 *
 * Return: (1) if succeed
 * --------(-1) if it fails
 */
int execute_cmd(char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		if (execve(cmd, args, NULL) < 0)
			return (-1);
	}
	else
		wait(&status);
	return (1);
}