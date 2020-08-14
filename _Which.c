#include "shell.h"

char *_getenv(const char *name)
{
    int x = 0, y = 0;
    if (name == NULL)
        return (NULL);
    while (environ[x])
    {
        while(environ[x][y] == name[y])
            y++;
        if (environ[x][y] == '=')
        {
            y++;
            return (&(environ[x][y]));
        }
        x++;
        y = 0;
    }
    write(STDOUT_FILENO, "ERROR ", 6);
    return (NULL);
}

int PathCheck(char *str)
{
    struct stat buff;
    if (stat(str, &buff) == 0)
    {
        return (0);
    }
    return (-1);
}

char *_witch(char *av)
{
    char *token, *tmp, *dir, *duplicate;
    int x, check = 0;

    dir = _getenv("PATH");
    duplicate = strdup(dir);
    token = strtok(duplicate, ":");
    if (av == NULL)
        return (NULL);
    for (x = 1; av[x] ; x++)
    {
        while (token != NULL)
        {
            tmp = strdup(token);
            tmp = strcat(tmp, "/");

            tmp = strcat(tmp, av);

            if (PathCheck(tmp) == 0)
            {
                check = 1;
                break;
            }
            token = strtok(NULL, ":");
            free(tmp);
        }
        if (check == 1 || token == NULL)
            break;
    }
    if (check == 0)
    {
        write(1, "lol" , 3);
        write(1, ": Command not found\n", 20);
        return (NULL);
    }
    return (tmp);
}