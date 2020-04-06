/**
 * Holberton School Project - Simple Shell
 * Author: KoeusIss
 *
 * Parser - a file to handle parse thechnique of the given command
 * helps to determines if the command is in path or not
 * dispatching between builtins or system function
 */
#include "shell.h"
#define PATH_DELIM ":"

/**
 * _which - locates the given filename if the path
 * @filename: the given filename
 *
 * Return: (*pointer) to the pathname of the file/command
 * --------(NULL) if not ofund
 */
char *_which(char *filename)
{
	char *path, *cmd, **paths, *_path;
	struct stat st;
	int i = 0;

	path = getenv("PATH");
	_path = strdup(path);
	paths = tokenize(_path, PATH_DELIM);
	if (stat(filename, &st) == 0)
		return (filename);
	else
	{
		while (paths[i])
		{
			cmd = _strcat(paths[i], filename);
			if (stat(cmd, &st) == 0)
				break;
			i++;
		}
	}
	free(paths);
	return (cmd);
}