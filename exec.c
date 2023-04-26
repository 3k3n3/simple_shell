#include "main.h"

/**
 * exec - Execute commands
 * @argv: array of arguments/commands
 *
 * Return: void
 */
void exec(char **argv)
{
	pid_t child_pid = fork();
	int status, i;

	for (i = 0; i < num_builtins(); i++)
	{
		if (_strcmp(argv[0], builtins[i].name) == 0)
		{
			(*builtins[i].func)(argv);
			return;
		}
	}

	if (child_pid == -1)
	{
		perror(*argv);
		exit(1);
	}
	else if (child_pid == 0)
	{
		execvp(argv[0], argv);
		perror(*argv);
		exit(1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
