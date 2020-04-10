#include "shell.h"

/**
 * cd - changes directory
 * @path: the given destination path
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int cd(char *path)
{
	return (chdir(path));
}
