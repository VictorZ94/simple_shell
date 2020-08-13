#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
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

int find(char *str)
{
      struct stat st;

      if (stat(str, &st) == 0)
      {
            return (0);
      }
      return (-1);
}

int main(int ac, char *av[])
{
    char *token, *tmp, *dir, *duplicate;
    int x, check = 0;
    struct stat statbuf;

    dir = _getenv("PATH");
    duplicate = strdup(dir);
    token = strtok(duplicate, ":");

    for (x = 1; x < ac; x++)
    {
        while (token != NULL)
        {
            tmp = strdup(token);
            tmp = strcat(tmp, "/");

            tmp = strcat(tmp, av[x]);

            if (find(tmp) == 0)
            {
                check = 1;
                printf("%s\n", tmp);
                break;
            }
            token = strtok(NULL, ":");
            free(tmp);
        }
        if (check == 0)
            printf("NOT FOUND\n");
    }
    return (0);
}
