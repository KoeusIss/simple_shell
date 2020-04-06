#include "shell.h"

/**
 * error - the error handler of the hsh project
 * @code: the given code of the error
 *
 * Return: void
 */
void error(int code)
{
	int i = 0;
	err_t errors[] = {
		{1, "General error"},
		{2, "Missing keyword, command, or permission problem"},
		{126, "Permission problem or command is not executable"},
		{127, "command not found"},
		{128, "Invalid argument to exit"},
		{129, "Fatal error signal 1"},
		{130, "Script terminated by Control-C"},
		{0, NULL}
	};

	while (errors[i].txt)
	{
		if (errors[i].code == code)
		{
			dprintf(STDERR_FILENO, "%s\n", errors[i].txt);
			exit(errors[i].code);
		}
	}
}
