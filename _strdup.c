#include "shell.h"

/**
 * _strdup - Duplicate a string in a new address memory
 * @str: string to duplicate
 *
 * Return: pointer to char
 */
char *_strdup(char *str)
{
	char *p;
	int i, j;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i])
		i++;

	p = malloc(sizeof(char) * i + 1024);
	if (!p)
	{
		return ('\0');
	}
	j = 0;
	while (j <= i)
	{
		p[j] = str[j];
		j++;
	}
return (p);
}
