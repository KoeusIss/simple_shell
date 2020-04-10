#include "shell.h"
#define PROMPT "#Cisfun$ "

/**
 * main - entry point of the shell program
 *
 * Return: 0 Always
 */
int main(void)
{
	char *line;
	char **cmd;
	int status;

	signal(SIGINT, sig_handler);
	while (1)
	{
		line = read_line(PROMPT);
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		cmd = parse_line(line);
		if (cmd == NULL)
			exit(EXIT_FAILURE);
		if (_strcmp(cmd[0], "cd") == 0)
		{
			if (cd(cmd[1]) < 0)
				perror(cmd[1]);
			continue;
		}
		status = execute_cmd(cmd);
		if (status < 0)
		{
			perror(cmd[0]);
			_exit(EXIT_FAILURE);
		}
	}
	free(line);
	free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * read_line - reads line from standard input
 * @prompt: the given prompt to be siplayed
 *
 * Return: (Success) a pointer to the string
 * ------- (Fail) Null pointer
 */
char *read_line(char *prompt)
{
	char c, *line;
	char *start, *end;
	int size = BUF_SIZE, new_size, length, read_r;

	line = malloc(size * sizeof(line));
	if (line == NULL)
		return (NULL);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	for (start = line, end = line + size;;)
	{
		read_r = read(STDIN_FILENO, &c, 1);
		if (read_r == 0)
			return (NULL);
		*start++ = c;
		if (c == '\n')
		{
			*start = '\0';
			return (line);
		}
		if (start + 2 >= end)
		{
			new_size = size * 2;
			length = start - line;
			line = _realloc(line, size * sizeof(char),
					new_size * sizeof(char));
			if (line == NULL)
				return (NULL);
			size = new_size;
			end = line + size;
			start = line + length;
		}
	}
}

#define DELIMITER " \n\r\t\a"
#define TOKEN_SIZE 64

/**
 * split_line - splits a line to a tokens
 * @line: the given line
 *
 * Return: (Success) return a pointer to an array of tokens
 * ------- (Fail) return a null pointer
 */
char **parse_line(char *line)
{
	char *token, **token_v;
	size_t i = 0, size = TOKEN_SIZE, new_size;

	token_v = malloc(size * sizeof(char *));
	if (token_v == NULL)
		return (NULL);
	token = strtok(line, DELIMITER);
	while (token)
	{
		token_v[i++] = token;
		if (i + 2 >= size)
		{
			new_size = size * 2;
			token_v = _realloc(token_v, size * sizeof(char *),
					new_size * sizeof(char *));
			if (token_v == NULL)
				return (NULL);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	token_v[i] = NULL;
	return (token_v);
}

#undef DELIMITER

/**
 * launch_cmd - executes given command int a different process
 * @cmd: an array of tokens contains cmd and arguments
 *
 * Return: (Success) return a positive number (0)
 * ------- (Fail) return a negative integer (-1)
 */
int execute_cmd(char **filename)
{
	pid_t pid;
	char *cmd;
	int st;

	cmd = filename[0];
	if (_strchr(cmd, '/') == NULL)
		cmd = _which(filename[0]);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(cmd, filename, environ) == -1)
			return (-1);
	}
	else
	{
		waitpid(pid, &st, WUNTRACED);
	}
	return (0);
}

#define DELIMITER ":"
/**
 * parse_cmd - parses an executable command
 * @filename: the given command
 *
 * Return: void
 */
char *_which(char *filename)
{
	char *path, *p, **path_v, *cmd, *token;
	struct stat st;
	size_t i = 0, size = TOKEN_SIZE, new_size;

	path = getenv("PATH");
	if (path == NULL)
		path = ":bin:/usr/bin";
	p = _strdup(path);
	path_v = malloc(size * sizeof(char *));
	if (path_v == NULL)
		return (NULL);
	if (stat(filename, &st) == 0)
		return (filename);
	token = strtok(p, DELIMITER);
	while (token)
	{
		path_v[i++] = token;
		if (i + 2 >= size)
		{
			new_size = size * 2;
			path_v = _realloc(path_v, size * sizeof(char *),
					new_size * sizeof(char *));
			if (path_v == NULL)
				return (NULL);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	path_v[i] = NULL;
	i = 0;
	while (path_v[i])
	{
		cmd = _strcat(path_v[i], filename);
		if (is_cmd(cmd))
			break;
		i++;
	}
	return (cmd);
}
#undef DELIMITER
