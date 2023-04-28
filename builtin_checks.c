#include "main.h"


/**
 * check_setenv - check setenv
 * @str: string
 *
 * Return: 0 or 1
 */
int check_setenv(char *str)
{
	char *cpy = _strdup(str), *name = NULL, *value = NULL;

	if (strcmp(_strtok(cpy, ' '), "setenv") == 0)
	{
		name = _strtok(NULL, ' ');
		value = _strtok(NULL, ' ');
		if (name == NULL || value == NULL)
		{
			write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 34);
			free(cpy);
			return (1);
		}
		set_env(name, value, 1);
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * check_unsetenv - check for unsetenv
 * @str: string
 *
 * Return: 0 or 1
 */
int check_unsetenv(char *str)
{
	char *cpy = _strdup(str), *token = NULL;

	if (strcmp(_strtok(cpy, ' '), "unsetenv") == 0)
	{
		token = _strtok(NULL, ' ');
		if (token == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 28);
			free(cpy);
			return (1);
		}
		if (unset_env(token) == -1)
		{
			write(STDERR_FILENO, "can't unset non-existent variable\n", 35);
			free(cpy);
			return (1);
		}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * check_exit - check for exit
 * @str: string
 *
 * Return: 0 or 1
 */
int check_exit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(_strtok(cpy, ' '), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
