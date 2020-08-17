#include "shell.h"

int verifyLine(ssize_t value)
{
    if (value == EOF)
    {
		write(1, "\n", 2);
        return (1);
    }
    return (0);
}

char **_readline(char *line)
{
    char **arguments;
    
    arguments = tokenizer(line);

    return (arguments);
}
