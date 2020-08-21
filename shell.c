#include "shell.h"
/**
 * main - our own shell
 *
 * Return: on succes 0, otherwise 1
 */
int main(void)
{
	size_t len;
	ssize_t read = 0;
	char *line = NULL, *directory = NULL;
	char **readline;
	int check;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);

	while ((read = getline(&line, &len, stdin)) != EOF)
	{
		readline = _readline(line);
		check = PathCheck(readline[0]);
		if (check == 0)
			directory = readline[0];
		else
			directory = findPath(readline[0]);

		if (directory != NULL)
			_execve(directory, readline);

		if (check != 0)
			free(directory);

		_freeargs(readline);

		if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	}
	if (isatty(STDIN_FILENO) == 1)
		write(1, "\n", 2);
	free(line);
	return (0);
}
