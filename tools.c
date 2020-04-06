/**
 * Holberton School Project - Simple Shell
 * Author: KoeusIss
 * 
 * Tools - A bunch of usefull function helps to allocate, reallocate, sizeof
 * String length determines, concatenates string...
 */
#include "shell.h"

/**
 * _strlen - finds the length of string
 * @str: the given string
 *
 */
int _strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * path_concat - concatenates two string
 * @first: the first given destination
 * @second: the second given source
 *
 * Return: (*pointer) to the newly string
 * --------(NULL) if it failed
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i =0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}
