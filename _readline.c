#include "shell.h"

/**
 * _readline - read a entire line
 * @line: input of getline
 *
 * Return: arguments array of pointers
 */
char **_readline(char *line)
{
	char **arguments;

	arguments = tokenizer(line);
	extraFunctions(arguments, line);
	return (arguments);
}

/**
 * extraFunctions - function that check env and exit
 * @argv: input command
 * @line: input command
 *
 * Return: void
 */
void extraFunctions(char **argv, char *line)
{
	int x = 0;

	if (argv == NULL || *argv == NULL)
		return;

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(line);
		_freeargs(argv);
		exit(127);
	}

	if (_strcmp(argv[0], "env") == 0)
	{
		while (environ[x])
		{
			_puts2(environ[x]);
			x++;
		}
	}
}
