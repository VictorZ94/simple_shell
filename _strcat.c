#include "shell.h"
/**
 * _strcat - concaten two string
 * @dest: Argument that it recieve
 * @src: Argument that it give
 *
 * Return: Pointer to char
 */
/**
 * _strcat - main
 * @dest: char
 * @src: char
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int aLength = strlen(dest);
	int counter = 0;

	while (src[counter] != '\0')
	{
		dest[aLength] = src[counter];
		aLength++;
		counter++;
	}
	return (dest);
}

