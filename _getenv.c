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

	if (str == NULL)
		return (1);

	if (stat(str, &buff) == 0)
	{
		return (0);
	}
	return (1);
}

/**
 * findPath - funtion return the path whether it exist.
 * @av: string directory.
 * @argv: arary of pointers.
 * @i: count the amount to commands.
 *
 * Return: On success a pointer path, Otherwise NULL.
 */
char *findPath(char *av, char **argv, int i)
{
	char *token, *tmp, *dir, *duplicate;
	int x, check = 0;

	if (av == NULL)
		return (NULL);

	dir = _getenv("PATH");
	duplicate = _strdup(dir);
	token = strtok(duplicate, ":");
	for (x = 1; av[x] ; x++)
	{
		while (token != NULL)
		{
			tmp = _strdup(token);
			tmp = _strcat(tmp, "/");

			tmp = _strcat(tmp, av);
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
		_puts(*argv);
		write(1, ": ", 2);
		_putchar(i + '0');
		write(1, ": not found\n", 12);
		free(duplicate);
		return (NULL);
	}
	free(duplicate);
	return (tmp);
}
