#include "shell.h"

/**
 * main - Enter point simple shell
 *
 * Return: On success 0, Otherwise 1.
 */
int main(void)
{
	int check = 0, i = 0;
	ssize_t read = 0;
	size_t len[BUFFSIZE];
	char *line = NULL, *argv[BUFFSIZE];
	char *token = NULL;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		read = getline(&line, len, stdin);
		if (read == EOF)
		{
			write(1, "\n", 2);
			break;
		}
		if (line == NULL)
			continue;
		token = strtok(line, " \n");
		if (PathCheck(token) == 0)
			check = 1;
		while (token != NULL)
		{
			argv[i] = token; /* array of pointers */
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
		if (check == 0)
			token = _witch(argv[0]);

		execute(token, argv, check);
		check = 0;
		i = 0;
	} while (isatty(STDIN_FILENO) == 1);
	free(line);
	return (0);
}
