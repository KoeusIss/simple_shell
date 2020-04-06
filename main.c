#include "shell.h"

/**
 * main - the main function of the hsh project
 *
 * Return: 0 Always
 */
int main(void)
{
	char *buffer;
	char prompt[] = "#Cisfun$ ";
	char delim[] = " \n\t\a";
	int read, status;
	size_t size = BUFFER_SIZE;
	char **av;
	pid_t pid;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		error(1);
	while (read != (-1))
	{
		printf("%s", prompt);
		read = getline(&buffer, &size, stdin);
		av = tokenize(buffer, delim);
		pid = fork();
		if (pid == -1)
			perror("./shell");
		if (pid == 0)
		{
			if (execve(_which(av[0]), av, NULL) == -1)
				perror("./shell");
		}
		else
			wait(&status);
	}
	return (0);
}
