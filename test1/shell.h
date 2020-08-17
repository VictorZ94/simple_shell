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
/*----- enviroment variable ---- */
extern char **environ;

char *_getenv(const char *name);
int PathCheck(char *str);
char *_witch(char *av);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

#endif /* SHELL_SIMPLE */
