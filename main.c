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
		return (-1);
	while (status)
	{
		printf(PROMPT);
		read = getline(&buffer, &size, stdin);
		if (read == (-1))
		{
			printf("\n");
			free(buffer);
			break;
		}
		av = tokenize(buffer, DELIMITER);
		cmd = _which(av[0]);
		status = execute_cmd(cmd, av);
		free(buffer);
		free(av);
		free(cmd);
	}
	return (0);
}