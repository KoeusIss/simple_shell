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
	if (stat(filename, &st) == 0)
		return (filename);
	paths = tokenize(_path, PATH_DELIM);
	while (paths[i])
	{
		cmd = _strcat(paths[i], filename);
		if (stat(cmd, &st) == 0)
			break;
		i++;
	}
	free(paths);
	return (cmd);
}
