#include "main.h"


/**
 * _strlen - string length
 * @s: string
 *
 * Return: string length
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}


/**
 * _strdup - duplicate str
 * @str: str
 *
 * Return: duplicate str
 */
char *_strdup(const char *str)
{
	int i = 0, n = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	do {
		n++;
	} while (str[n - 1]);

	dup = malloc(sizeof(char) * n);

	if (dup == NULL)
		return (NULL);

	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);
}


/**
 * _atoi - converts string to an integer
 * @s: string
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	char c;
	unsigned int i, num = 0, null = -1;
	unsigned int j = _strlen(s) - 1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = s[i];
		if (c == '-')
			sign *= -1;
		if (c > 47 && c < 58)
		{
			num = num * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c > 47 && c < 58))
				break;
		}
	}
	if (sign == -1)
		num *= -1;
	if (j == null)
		return (0);

	return (num);
}


/**
 * _strcpy - copies a str to the dest
 * @dest: destination
 * @src: source
 *
 * Return: copy of str
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strncpy - copy a string
 * @dest: string dest
 * @src: string to cpy
 * @n: bytes
 *
 * Return: copy a string to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (i < n)
	{
		if (src[i] == '\0')
			j = 1;
		if (j == 0)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}

	return (dest);
}
