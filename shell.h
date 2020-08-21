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

char **_readline(char *line);
int verifyLine(ssize_t value);
char **tokenizer(char *line);
char *startEnv(char *line);
char *_getenv(const char *name);
int tokeLen(char *line);
char *findPath(char *av, char **argv, int i);
void _execve(char *directory, char **arguments);
int PathCheck(char *str);
char *_strdup(char *str);
void extraFunctions(char **argv, char *line);
char *_strcat(char *dest, char *src);
void _free(char **line);
void _freeargs(char **str);
int _strlen(char *s);
int _strcmp(const char *s1, char *s2);
char *_strtok(char *str, const char *delim);
int _putchar(int c);
int _puts(const char *s);
int _puts2(const char *s);

#endif /* SHELL_SIMPLE */
