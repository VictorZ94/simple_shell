#include "shell.h"

/**
 * _putchar - print standard output char by char
 * @c: character to print
 *
 * Return: standard output
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints an string
 * @s: string to print
 *
 * Return: always 0.
 */
int _puts(const char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (0);
}

/**
 * _puts2 - function that prints an string
 * @s: string to print
 *
 * Return: always 0.
 */
int _puts2(const char *s)
{
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
