#include "shell.h"

int main(void)
{
    size_t len[BUFFSIZE];
    ssize_t read = 0;
    char *line, *directory;
    char **readline;
    int checkLine = 0, x = 0;

    do
    {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
        read = getline(&line, len, stdin);
    /*--------------------------------B----------------------- */
        if (checkLine = verifyLine(read) == 1)
            break;
        readline = _readline(line);
        directory = startEnv(readline[0]);
        _execve(directory, readline);
    } while (isatty(STDIN_FILENO) == 1);
}