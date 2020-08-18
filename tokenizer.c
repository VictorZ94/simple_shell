#include "shell.h"

char **tokenizer(char *line)
{
    int x = 0, tokenLen = 0;
    char **arguments;
    char *token = NULL;

    arguments = (char **)malloc(sizeof(char *) * BUFFSIZE);
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
