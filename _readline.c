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
    extraFunctions(arguments);
    return (arguments);
}

void extraFunctions(char **argv)
{
    int x = 0;

    if(strcmp(argv[0], "exit") == 0)
			exit(EXIT_SUCCESS);
    if(strcmp(argv[0], "env") == 0)
	{
        while(environ[x])
        {
            printf("%s\n", environ[x]);
            x++;
        }
    }
}
