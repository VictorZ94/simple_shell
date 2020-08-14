#include "shell.h"

int main(void)
{
    int check = 0, status = 0, i = 0;
    pid_t my_pid;
    ssize_t read = 0;
    size_t len[BUFFSIZE];
    char *line = NULL, *argv[BUFFSIZE];
    char *token = NULL;

    do
    {
        if (isatty(STDIN_FILENO) == 1)
            write(1, "$ ", 2);
        read = getline(&line, len, stdin);
        if (read == EOF)
        {
            write(1, "\n", 2);
            break;
        }
        if (line == NULL)
            continue;
        token = strdup(line);
        token = strtok(token, "\n ");
        if (PathCheck(token) == 0)
            check = 1;
        while (token != NULL)
		{
			argv[i] = token; /* array of pointers */
			i++;
			token = strtok(NULL, " \n");
		}
        argv[i] = NULL;
        if (check == 0)
            token = _witch(argv[0]);
        my_pid = fork();
		if (my_pid == -1)
			exit(EXIT_FAILURE);
		if (my_pid == 0 && check == 0)
		{
			if (execve(token, argv, NULL) == -1)
				exit(EXIT_FAILURE);
		}
        else if(my_pid == 0 && check == 1) 
        {
            if (execve(argv[0], argv, NULL) == -1)
			exit(EXIT_FAILURE);
        }
		else
			wait(&status);
        check = 0;
        i = 0;
    }while(isatty(STDIN_FILENO) == 1);
}
