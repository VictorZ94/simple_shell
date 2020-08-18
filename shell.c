#include "shell.h"
/**
 * main
 * 
 * fix?
 */
int main(void)
{
    size_t len[BUFFSIZE];
    ssize_t read = 0;
    char *line = NULL, *directory = NULL;
    char **readline;
    int checkLine = 0, tlen = 0;

    do
    {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
        read = getline(&line, len, stdin);
        checkLine = verifyLine(read);
        if (*line == '\n')
            continue;
        if (checkLine == 1)
            break;
        readline = _readline(line);
        tlen = tokeLen(line);
        directory = startEnv(readline[0]);
        _execve(directory, readline);
    } while (isatty(STDIN_FILENO) == 1);

    return (0);
}