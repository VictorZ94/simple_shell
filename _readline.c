#include "shell.h"

/**
 * verifyLine - check if input is different to EOF
 * @value: value len
 *
 * Return: on success 0, otherwhise 1
 */
int verifyLine(ssize_t value)
{
	if (value == EOF)
	{
		write(1, "\n", 2);
		return (1);
	}
	return (0);
}

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
	extraFunctions(arguments);
	return (arguments);
}

/**
 * extraFunctions - function that check env and exit
 * @argv: input command
 *
 * Return: void
 */
void extraFunctions(char **argv)
{
	int x = 0;

	if (strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	if (strcmp(argv[0], "env") == 0)
	{
		while (environ[x])
		{
			printf("%s\n", environ[x]);
			x++;
		}
	}
}
