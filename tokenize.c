#include "main.h"

/**
 * split_line - splits parsed arguments into tokens
 * @line: read line from stdin
 * @nread: num of chars read in line
 *
 * Return: Array of strings
 */
char **split_line(char *line, ssize_t nread)
{
	int len = 0;
	char *delim = " \t\r\n";

	char **tokens =  malloc(sizeof(char) * nread);
	char *token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[len] = token;
		len++;
		if (len >= nread)
		{
			nread = (int) (nread * 1.5);
			tokens = realloc(tokens, nread * sizeof(char *));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return (tokens);
}

