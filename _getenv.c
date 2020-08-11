#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
int main () 
{
    printf("PATH : %s\n", _getenv("PATH"));
    printf("HOME : %s\n", _getenv("H"));
    return (0);
}
