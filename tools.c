/**
 * Holberton School Project - Simple Shell
 * Author: KoeusIss
 * 
 * Tools - collection of tools
 * fill_array: finds string length
 * _realloc: reallocate a memory for an array
 *
 */
#include "shell.h"

/**
 * fill_an_array - fill an array with elements
 * @a: the given array
 * @el: the given element
 * @len: the length of the array
 *
 * Return: pointer to filled array
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the previous memory
 * @old_size: the old size
 * @new_size: the new size
 *
 * Return: a pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;
	unsigned int i;
	char *p;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		i = 0;
		p = ptr;
		while (i < old_size)
		{
			fill_an_array(result, *p, old_size);
			p++;
			i++;
		}
		free(ptr);
	}
	return (result);
}