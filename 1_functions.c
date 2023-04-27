#include "main.h"

/**
 * is_exec - check if path is an executable
 * @path: filepath
 *
 * Return: status of path
 */
int is_exec(char *path)
{
	if (file_dir(path) == 0)
	{
		if (path[0] == '/')
			perror(path);
		else
			perror(path);
		return (1);
	}
	if (access(path, X_OK))
		return (2);
	return (0);
}


/**
 * file_dir - check if the path is directory
 * @path: file path
 *
 * Return: status
 */
int file_dir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}


/**
 * get_return_val - get return value
 * @str: string
 *
 * Return: exit value
 */
int get_return_val(char *str)
{
	char *cpy = _strdup(str), *token;
	int exit_val = 0;

	token = _strtok(cpy, ' ');
	token = _strtok(NULL, ' ');
	if (token == NULL)
	{
		free(cpy);
		return (0);
	}
	if (is_digit(token) == 0)
		exit_val = _atoi(token);
	else
	{
		free(cpy);
		write(STDERR_FILENO, "exit: Unable to parse number\n", 22);
		return (-1);
	}

	free(cpy);
	if (exit_val < 0)
	{
		write(STDERR_FILENO, "exit: Unable to parse number\n", 22);
		exit_val = (-1);
	}

	return (exit_val);
}


/**
 * child_fork - a process forked from a parent process
 * @child_pid: child process PID
 * @name: name of program/process
 *
 * Return: child_PID
 */
int child_fork(pid_t child_pid, char *name)
{
	child_pid = fork();

	if (child_pid == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}

	return (child_pid);
}


/**
 * isatty_signal - finds signal and checks the isatty function
 *
 * Return: void
 */
void isatty_signal(void)
{
	signal(SIGINT, sig_handler);
	if ((isatty(STDIN_FILENO) == 1))
		write(STDOUT_FILENO, "$ ", 3);
}
