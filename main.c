#include "shell.h"

#define PROMPT "#Cisfun$ "
#define DELIMITER " \n\t\a\r"

/**
 * main - the main function of the hsh project
 *
 * Return: 0 Always
 */
int main(void)
{
	char *cmd, *buffer, **av;
	int read = 1, status = 1;
	size_t size = BUFFER_SIZE;

	buffer = malloc(size);
	if (!buffer)
		perror("General");
	while (status)
	{
		printf(PROMPT);
		read = getline(&buffer, &size, stdin);
		if (read == (-1))
		{
			printf("\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		av = tokenize(buffer, DELIMITER);
		if (!av)
			perror("General");
		if (_strcmp(av[0], "exit") == 0)
			quit();
		cmd = _which(av[0]);
		if (!cmd)
			perror("General");
		status = execute_cmd(cmd, av);
		if (status < 0)
			perror(av[0]);
		free(buffer);
		free(av);
		free(cmd);
	}
	return (0);
}