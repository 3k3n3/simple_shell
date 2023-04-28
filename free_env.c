#include "main.h"


/**
 * free_buff_env - frees buffer and environ variable
 * @str: buffer
 *
 * Return: void
 */
void free_buff_env(char *str)
{
	free(str);
}


/**
 * wait_free - waits & frees things
 * @status: Status of the process
 * @argv: Array to free
 * @dup: Duplicated array to free
 *
 * Return: Returns the status of isatty
 */
void wait_free(int status, char **argv, char *dup)
{
	wait(&status);
	free_array_dup(argv, dup);
}


/**
 * free_exit - frees buffer and exit
 * @buffer: buffer
 *
 * Return: void
 */
void free_exit(char *buffer)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}


/**
 * free_array_dup - frees an array and dup string
 * @arr: array to free
 * @dup: dup str
 *
 * Return: void
 */
void free_array_dup(char **arr, char *dup)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}

	free(arr[i]);
	free(arr);
	free(dup);
}


/**
 * free_env - frees all environ used in the set_env
 * @var: variable name
 *
 * Return: void
 */
void free_env(char *var)
{
	size_t len = 0;
	int i = 0;

	len = strlen(var);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], var, len) == 0)
		{
			free(environ[i]);
		}
		i++;
	}
}
