#include "shell.h"

/**
 * _strlen - finds the length of string
 * @str: the given string
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

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
	char *token;
	int i = 0;
	char **token_v;

	if (!line)
		return (NULL);
	token_v = malloc(MAX_TOKEN);
	if (!token_v)
		return (NULL);
	token = strtok(line, delim);
	while (token)
	{
		token_v[i++] = token;
		token = strtok(NULL, delim);
	}
	token_v[i] = NULL;
	return (token_v);
}

/**
 * path_concat - concatenates two string
 * @dest: the first given destination
 * @src: the second given source
 *
 * Return: (*pointer) to the newly string
 * --------(NULL) if it failed
 */
char *path_concat(char *dest, char *src)
{
	int dest_l, src_l, i = 0, j = 0;
	char *result;

	dest_l = _strlen(dest);
	src_l = _strlen(src);
	result = malloc(dest_l + src_l + 2);
	if (!result)
		return (NULL);
	while (dest[j])
	{
		result[i] = dest[j];
		j++;
		i++;
	}
	result[i++] = '/';
	j = 0;
	while (src[j])
	{
		result[i] = src[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/**
 * _which - locates the given filename if the path
 * @filename: the given filename
 *
 * Return: (*pointer) to the pathname of the file/command
 * --------(NULL) if not ofund
 */
char *_which(char *filename)
{
	char **tokens;
	char *path;
	struct stat st;
	char *command;
	int i = 0;

	path = getenv("PATH");
	tokens = tokenize(path, ":");
	if (stat(filename, &st) == 0)
	{
		return (filename);
	}
	else
	{
		while (tokens[i])
		{
			command = path_concat(tokens[i], filename);
			if (stat(command, &st) == 0)
			{
				return (command);
			}
			i++;
		}
	}
	return (NULL);
}
