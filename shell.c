#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - first version shell program.
 *
 * Return: Always 0.
 */
int main()
{
	size_t len;
	int status = 0, i;
	ssize_t read = 0; /* to use in getline - returns it read*/
	char *line = NULL; /* parameter recorded by terminal */
	pid_t my_pid = 0; /* New process for every command */
	char **argv = NULL; /* it is the new array of pointers at new strings */
	char *token = NULL; /* string that I want splits in tokens */

	write(1, "#cisfun$ ", 9);
	while((read = getline(&line, &len, stdin)) != EOF)
	{
		argv = malloc(sizeof(char *));
		token = strtok(line, "\n");
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
		argv[i] = NULL;
		if ((my_pid = fork()) == -1)
		{
			perror("Error fork");
			exit(EXIT_FAILURE);
		}
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
		
		write(1, "#cisfun$ ", 9);
	}
	write(1, "\n", 1);
	return (0);
}
