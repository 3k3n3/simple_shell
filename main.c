#include "main.h"

/**
 * main - Recreation of a "sh"
 * @argc: argunment count
 * @argv: argument vector, array of args
 *
 * Return: 0 If succeed, or the number of the error
 */
int main(__attribute__((unused))int argc, char **argv)
{
	size_t i = 0;
	int count = 0, builtin = 0, status = 0, exit_val = 0, child_pid = 0;
	char *buffer = NULL, *dup = NULL;

	while (1)
	{
		isatty_signal();
		count = getline(&buffer, &i, stdin);
		if (count == -1)
			free_exit(buffer);
		if (check_hash(buffer) == -1)
			continue;

		buffer = clean_str(buffer, count);
		builtin = check_builtin(buffer);
		if (builtin == 1)
		{
			if (get_return_val(buffer) >= 0)
				break;
			continue;
		}
		dup = _strdup(buffer);
		argv = tokenize(dup, builtin);
		if ((builtin == 0 && is_exec(argv[0]) == 0))
			child_pid = child_fork(child_pid, argv[0]);
		else
			child_pid = 1;
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			break;
		}
		if (child_pid != 0)
			wait_free(status, argv, dup);
	}
	if (builtin != 1)
		free_array_dup(argv, dup);

	free_buff_env(buffer);
	return (exit_val);
}
