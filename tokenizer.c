#include "shell.h"

/**
 * tokenizer - tokenize at first string
 * @line: lien to tokenizer
 *
 * Return: array of pointer tokenized or NULL
 */
char **tokenizer(char *line)
{
	int x = 0, tokenLen = 0;
	char **arguments;
	char *token = NULL;

	arguments = (char **)malloc(sizeof(char *) * BUFFSIZE);
	if (line == NULL)
		return (0);
	tokenLen = tokeLen(line);
	token = strtok(line, " \n");
	while (x < tokenLen)
	{
		arguments[x] = strdup(token);
		token = strtok(NULL, " \n");
		x++;
	}
	arguments[x] = '\0';
	return (arguments);
}

/**
 * tokeLen - count the amount of array of pointers.
 * @line: line to tokenizer
 *
 * Return: integer
 */
int tokeLen(char *line)
{
	int x = 0;
	char *token;
	char *str;

	str = strdup(line);
	token = strtok(str, " ");
	while (token != NULL)
	{
		x++;
		token = strtok(NULL, " ");
	}
	free(str);
	return (x);
}
