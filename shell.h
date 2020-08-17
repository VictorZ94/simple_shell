#ifndef SHELL_SIMPLE
#define SHELL_SIMPLE
/*----- Standard libraries -------*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*----- system libraries ----*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFFSIZE 1024
typedef struct argumentList{
    char *arg;
    struct argumentList *next;
}node;

/*----- enviroment variable ---- */
extern char **environ;

char **_readline(char *line);
int verifyLine(ssize_t value);
char **tokenizer(char *line);
char *startEnv(char *line);
int tokeLen(char *line);
char *findPath(char *av);
void _execve(char *directory, char **arguments);
int PathCheck(char *str);
#endif /* SHELL_SIMPLE */
