#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int find(char *str);
char *_getenv(const char *name);

/**
 * find - find a path whether exist or not
 * 
 * Return: On seccess 1, Otherwhise 0
 */
int find(char *str)
{
      struct stat st;

      if (stat(str, &st) == 0)
      {
            return (1);
      }
      return (0);
}

/**
 * main find a path
 * 
 * Return: Always 0
 */
int main(int ac, char **av)
{
      const char *path = _getenv("PATH");
      char *token = NULL;
      char *copy = NULL;
      char *string = NULL;
      char *string2 = NULL;
      int i, value = 0;

      if (ac < 2)
      {
        printf("Usage: %s ...\n", av[0]);
        return (1);
      }
      copy = malloc(sizeof(path) + 1);
      if (!copy)
            return (1);

      strcpy(copy, path);
      token = strtok(copy, ":");
      i = 1;
      while(av[i])
      {
            while(token != NULL)
            {
                  string = strcat(token, "/");
                  string2 = strcat(string, av[i]);
                  value = find(string2);/* /bin/ls */
                  if (value == 1)
                        printf("%s\n", string2);

                  token = strtok(NULL, ":");
            }
            i++;
      }
      free(copy);
      return (0);
}
