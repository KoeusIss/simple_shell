#include "shell.h"

/**
 * tokenize - splits a given string to tokens
 * @line: the given string
 * @delim: the given delimiter
 *
 * Return: (*pointer) to an arrays of tokens
 * --------(NULL) if it fails
 */
char **tokenize(char *line, char *delim)
{
	char *token, **token_v;
	int i = 0, size = MAX_TOKEN;

	token_v = malloc(size * sizeof(char *));
	if (!token_v)
		return (NULL);
	token = strtok(line, delim);
	while (token)
	{
		token_v[i++] = token;
		if (i >= MAX_TOKEN)
		{
			size += MAX_TOKEN;
			token_v = realloc(token_v, size * sizeof(char *));
			if (!token_v)
				return (NULL);
		}
		token = strtok(NULL, delim);
	}
	token_v[i] = NULL;
	return (token_v);
}
