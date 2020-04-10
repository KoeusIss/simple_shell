#include "shell.h"

/**
 * _strlen - finds the length of a given string
 * @str: the given string
 *
 * Return: (Success) the length of the string
 * ------- (Fail) negative value
 */
int _strlen(char *str)
{
	char *ptr;
	if (str == NULL)
		return (-1);
	for (ptr = str; *ptr; ptr++)
		;
	return (ptr - str);
}

/**
 * _strcmp - compare two strings
 * @s1: the first given string
 * @s2: the second given string
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i;

	for (i = 0; s1[i]; i++)
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
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 *
 * Return: (Success) a pointer to the first occurence of c
 * ------- (Fail) return a null pointer
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}
/**
 * _strcat - concatenates two string
 * @first: the first given destination
 * @second: the second given source
 *
 * Return: (Success) to the newly string
 * ------- (Fail) if it failed
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
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
