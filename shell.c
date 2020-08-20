#include "shell.h"
/**
 * main - our own shell
 *
 * Return: on succes 0, otherwise 1
 */
int main(void)
{
	size_t len[BUFFSIZE];
	ssize_t read = 0;
	char *line = NULL, *directory = NULL;
	char **readline;
	int checkLine = 0;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		read = getline(&line, len, stdin);
		checkLine = verifyLine(read);
		if (checkLine == 1)
			break;
		if (*line == '\n')
			continue;
		readline = _readline(line);
		directory = startEnv(readline[0]);
		_execve(directory, readline);
		_freeargs(readline);
	} while (isatty(STDIN_FILENO) == 1);
	free(directory);
	free(line);
	return (0);
}
