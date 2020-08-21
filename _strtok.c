#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _strtok - function splits a string
 * @str: string to divide
 * @delim: string that contain delimiters
 *
 * Return: a pointer at the next string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *nxt;
	static int size;
	int i;

	if (!str || !delim)
		return (NULL);
	if (str != NULL)
	{
		nxt = str;
		size = strlen(str);
	} else if (size > 0)
	{
		nxt++, size--;
		str = nxt;
	} else
		str = NULL;

	while (*nxt)
	{
		i = strspn(nxt, delim);
		while (i > 1)
		{
			*nxt = '\0';
			nxt++;
			size--;
			i--;
		}
		if (i == 1)
		{
			*nxt = '\0';
			if (size > 1)
			{
				nxt--;
				size++;
			}
		}
		nxt++;
		size--;
	}
	return (str);
}
