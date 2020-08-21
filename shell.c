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
	int checkLine = 0, check;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		read = getline(&line, &len, stdin);
		checkLine = verifyLine(read);
		if (checkLine == 1)
			break;
		if (*line == '\n')
			continue;
		readline = _readline(line);
		check = PathCheck(readline[0]);
		if (check == 0)
			directory = readline[0];
		else
			directory = findPath(readline[0]);

		_execve(directory, readline);
		_freeargs(readline);
		if (directory != NULL && check != 0)
			free(directory);
	} while (isatty(STDIN_FILENO) == 1);
	free(line);
	return (0);
}
