#include "shell.h"

/**
 * _execve - function that executes the commands
 * @directory: directories of path
 * @arguments: array of pointers
 *
 * Return: void
 */
void _execve(char *directory, char **arguments)
{
	pid_t my_pid;
	int status = 0;

	my_pid = fork();
	if (my_pid == -1)
		exit(EXIT_FAILURE);
	if (my_pid == 0)
	{
		if (execve(directory, arguments, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
