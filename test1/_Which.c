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
char *_witch(char *av)
{
	char *token, *tmp, *dir, *duplicate;
	int x, check = 0;

	dir = _getenv("PATH");
	duplicate = _strdup(dir);
	token = strtok(duplicate, ":");
	if (av == NULL)
		return (NULL);
	for (x = 1; av[x] ; x++)
	{
		while (token != NULL)
		{
			tmp = _strdup(token);
			tmp = _strcat(_strcat(tmp, "/"), av); /* /bin/ */
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
		write(1, "lol", 3);
		write(1, ": Command not found\n", 20);
		return (NULL);
	}
	free(duplicate);
	return (tmp);
}

/**
 * execute - program execute a command
 * @token: first command concatenate
 * @argv: command without modify
 * @check: check boolean
 *
 * Return: void.
 */
void execute(char *token, char **argv, int check)
{
	pid_t my_pid;
	int status = 0;

	my_pid = fork();
	if (my_pid == -1)
		exit(EXIT_FAILURE);
	if (my_pid == 0 && check == 0)
	{
		if (execve(token, argv, NULL) == -1)
			exit(EXIT_FAILURE);

	}
	else if (my_pid == 0 && check == 1)
	{
		if (execve(argv[0], argv, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
