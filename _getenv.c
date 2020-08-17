#include "shell.h"
/**
 * _getenv - function get directories of variable environment.
 * @name: environment variable's name
 *
 * Return: On success return path, Otherwise NULL
 */
char *_getenv(const char *name)
{
	int x = 0, y = 0;

	if (name == NULL)
		return (NULL);
	while (environ[x])
	{
		while (environ[x][y] == name[y])
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

/**
 * PathCheck - function checks if an directory exist or not
 * @str: string directory to check
 *
 * Return: On success 0, Otherwise -1.
 */
int PathCheck(char *str)
{
	struct stat buff;

	if (stat(str, &buff) == 0)
	{
		return (0);
	}
	return (-1);
}

/**
 * _witch - funtion return the path whether it exist.
 * @av: string directory.
 *
 * Return: On success a pointer path, Otherwise NULL.
 */
char *findPath(char *av)
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
		write(1, av, strlen(av));
		write(1, ": command not found\n", 20);
		return (NULL);
	}
	return (tmp);
}

char *startEnv(char *line)
{
    char *directory = NULL;
    int check = 1;

    if (check = PathCheck(line) == 0)
        return (line);
    directory = findPath(line);
    if (directory == NULL)
        return (NULL);
    return (directory);
}