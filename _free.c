#include "shell.h"

/**
 * _freeargs - free array of pointers
 * @str: doble pointer
 *
 * Return: void.
 */
void _freeargs(char **str)
{
	int i;

	if ((*str == NULL) | (str == NULL))
		return;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
