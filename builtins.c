#include "main.h"


/**
 * check_env - builtin checker for env
 * @str: string
 *
 * Return: 1 or 0 if cmd matches
 */
int check_env(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(_strtok(cpy, ' '), "env") == 0)
	{
		free(cpy);
		print_env();
		return (1);
	}
	free(cpy);

	return (0);
}


/**
 * check_hash - checks if # in str
 * @str: string/buffer
 *
 * Return: char or not, 0 or -1
 */
int check_hash(char *str)
{
	int i = 0, r = -1;

	if (str[0] == '#')
		return (r);

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10 && str[i] != '\t' && str[i] != '#')
		{
			r = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = _strtok(str, ' ');
			}
			break;
		}
		if (str[i] == '#')
			break;
		i++;
	}

	return (r);
}


/**
 * check_cd - check if cmd is cd
 * @str: string
 *
 * Return: cd function
 */
int check_cd(char *str)
{
	char *cpy = _strdup(str), *dir = NULL, *PWD = NULL, *buffer = NULL;
	int builtIn = 0, flag = 0;

	if (_strcmp(_strtok(cpy, ' '), "cd") == 0)
	{
		dir = _strtok(NULL, ' ');
		if (dir == NULL)
		{
			dir = get_env("HOME");
			flag++;
		}
		if (_strcmp(dir, "-") == 0)
		{
			dir = get_env("OLDPWD");
			flag++;
		}
		PWD = get_env("PWD");
		set_env("OLDPWD", PWD, 1);
		set_env("PWD", dir, 1);
		if (chdir(dir) != 0)
			perror(dir);
		builtIn++;
	}
	if (flag > 0)
		free(dir);

	free(cpy);
	free(buffer);
	free(PWD);

	return (builtIn);
}


/**
 * check_builtin - checks if cmd is a builtin
 * @str: string
 *
 * Return: status
 */
int check_builtin(char *str)
{
	if (check_cd(str) == 1)
		return (2);
	if (check_exit(str) == 1)
		return (1);
	if (check_env(str) == 1)
		return (3);
	if (check_unsetenv(str) == 1)
		return (4);
	if (check_setenv(str) == 1)
		return (5);
	/**
	 * if (checkHelp(str) == 1)
	 *	return (6);
	 * check unused
	 */
	return (0);
}


/**
 * path - checks if file exists
 * @filename: name of the file
 *
 * Return: Returns the absolute route of a file or NULL
 */
char *path(char *filename)
{
	char *PATH = get_env("PATH");
	char *cpy = _strdup(PATH), *concatenated = NULL;
	char *token = NULL, *absolute = NULL;
	struct stat st;

	token = _strtok(cpy, ':');
	concatenated = str_concat("/", filename);
	while (token != NULL)
	{
		absolute = str_concat(token, concatenated);
		if (stat(absolute, &st) == 0)
		{
			free(PATH);
			free(cpy);
			free(concatenated);
			return (absolute);
		}
		token = _strtok(NULL, ':');
		free(absolute);
	}
	free(PATH);
	free(concatenated);
	free(cpy);
	return (NULL);
}
