/**
 * Holberton School Project - Simple Shell
 * Author: KoeusIss
 * 
 * Strings - collection of string manupilation tools
 * _strlen: finds string length
 * _strcat: concatnates strings
 * _strdup: duplicates a string in another one
 * _strcmp: compares two strings
 * _strtok: splits a given string to tokens
 *
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

/**
 * _strdup - duplicates string
 * @str: given string
 *
 * Return: a pointer to the newly duplicated string
 */
char *_strdup(char *str)
{
	char *dupl;
	int size = 0;
	int i;

	if (str == NULL)
		return (NULL);
	while (*(str + size))
		size++;
	dupl = malloc(size + 1);
	if (dupl == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		*(dupl + i) = *(str + i);
		i++;
	}
	return (dupl);
}

/**
 * _strcmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: The differnce between two strings
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0;
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _strtok - Splits a given string to tokens
 * @str: a given string
 * @delim: the delimiter
 *
 * Return: a pointer to the first token
 * --------(NULL) if it fails
 */
