#include "shell.h"

char **tokenizer(char *line)
{
    int x = 0, tokenLen = 0, y = 0;
    char **arguments;
    char *token = NULL;

    arguments = malloc(sizeof(char *) * 1024);
    if (line == NULL)
        return (0);
    tokenLen = tokeLen(line);
    token = strdup(line);
    token = strtok(line, " \n");
    while (x < tokenLen)
    {
        arguments[x] = malloc(BUFFSIZE);
        arguments[x] = token;
        token = strtok(NULL, " \n");
        x++;
    }
    return (arguments);
}

int tokeLen(char *line)
{
    int x = 0;
    char *token;

    token = strdup(line);
    token = strtok(token, " ");
    while(token != NULL)
    {
        x++;
        token = strtok(NULL, " ");
    }
    free(token);
    return (x);
}
