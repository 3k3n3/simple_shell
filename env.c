#include "main.h"

/**
 * print_env - prints environment variables
 *
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}


/**
 * unset_env - deletes/unset variable name from env
 * @name: variable name
 *
 * Return: 0 if success else -1
 */
int unset_env(char *name)
{
	size_t len = 0;
	int i = 0, flag = 0;

	len = _strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			flag++;
			break;
		}
		i++;
	}
	if (flag > 0)
		return (0);
	return (-1);
}


/**
 * set_env - change or set new env variable
 * @name: variable name
 * @value: variable var
 * @overwrite: if variable should be overwritten or not
 *
 * Return: 0 on success or -1 on error
 */
int set_env(char *name, char *value, int overwrite)
{
	size_t len;
	int i = 0;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			if (overwrite == 2)
			{
				free(environ[i]);
			}
			environ[i] = create_var(name, value);
			if (!environ[i])
				return (-1);
			return (0);
		}
		i++;
	}
	environ[i] = create_var(name, value);
	if (!environ[i])
		return (-1);
	environ[i + 1] = NULL;

	return (0);
}


/**
 * create_var - create variable
 * @name: variable name
 * @value: variable value
 *
 * Return: new variable
 */
char *create_var(char *name, char *value)
{
	char *var = NULL, *app = NULL;

	app = str_concat(name, "=");
	if (!app)
		return (NULL);
	var = str_concat(app, value);

	if (!var)
		return (NULL);

	free(app);

	return (var);
}


/**
 * get_env - get var from environ variable
 * @name: variable name
 *
 * Return: value of the var or NULL
 */
char *get_env(const char *name)
{
	char *token, *val, *cpy;
	size_t i = 0;

	if (!name)
		exit(1);
	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token = _strtok(cpy, '=');
		if (_strcmp(name, token) == 0)
		{
			token = _strtok(NULL, '=');
			val = malloc(sizeof(char) * _strlen(token) + 1);
			if (!val)
			{
				free(cpy);
				return (NULL);
			}
			_strcpy(val, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (val);
}
