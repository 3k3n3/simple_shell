#include "main.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector (arrray conataining args)
 *
 * Return: Success 0 or -1 if fail
 */

int main(__attribute__((unused))int argc, char **argv)
{
	ssize_t nread;
	int i;
	size_t len = 0;
	char *line = NULL, *line_cpy = NULL;

	while (1 == 1)
	{
		printf("($) ");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
			return (-1);

		line_cpy =  malloc(sizeof(char) * nread);
		if (line_cpy == NULL)
			return (-1);

		_strcpy(line_cpy, line);

		argv = split_line(line, nread);
		if (argv[0] != NULL)
		{
			int is_builtin = 0;

			for (i = 0; i < num_builtins(); i++)
			{
				if (_strcmp(argv[0], builtins[i].name) == 0)
				{
					builtins[i].func(argv);
					is_builtin = 1;
					break;
				}
			}
			if (!is_builtin)
				exec(argv);
		}
	}
	free(line_cpy);
	free(argv);
	free(line);
}
