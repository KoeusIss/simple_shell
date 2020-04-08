#include "shell.h"

/**
 * execute_cmd - calls command line
 * @cmd: a given command line
 * @args: the given arguments vector
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
