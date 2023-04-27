#include "main.h"

/**
 * str_concat - concatenates two strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: concatenated str
 */
char *str_concat(char *str1, char *str2)
{
	char *str;
	int x = 0, y = 0, n = 0;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";

	do {
		x++;
	} while (str1[x - 1]);
	do {
		y++;
	} while (str2[y - 1]);

	str = malloc(sizeof(char) * (x + y - 1));
	if (str == NULL)
		return (NULL);

	for (n = 0; n < x; n++)
		str[n] = str1[n];

	for (n = 0; n < y; n++)
		str[n + x - 1] = str2[n];

	return (str);
}


/**
 * _strcmp - compare strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: dif in strsings
 */
int _strcmp(const char *str1, const char *str2)
{
	int i, x = 0, y = 0, res = 0;

	for (i = 0; i > -1 ; i++)
	{
		if (str1[i] != str2[i])
		{
			x = str1[i];
			y = str2[i];
			break;
		}
		else
		{
			if (str1[i] == '\0' || str2[i] == '\0')
				break;
		}
	}
	res = x - y;
	return (res);
}


/**
 * _strtok - implement strtok func
 * @str: str
 * @delim: delim
 *
 * Return: res
 */
char *_strtok(char *str, char delim)
{
	static char *token1, *token2;
	unsigned int n = 0;

	if (str != NULL)
		token2 = str;
	token1 = token2;
	if (token1 == NULL)
		return (NULL);

	while (token1[n] != '\0')
	{
		if (token1[n] != delim)
			break;
		n++;
	}
	if (token2[n] == '\0')
	{
		token2 = NULL;
		return (NULL);
	}
	token1 = token2 + n;
	token2 = token1;

	n = 0;
	while (token1[n] != '\0')
	{
		if (token2[n] == delim)
			break;
		n++;
	}
	if (token2[n] == '\0')
		token2 = NULL;
	else
	{
		token2[n] = '\0';
		token2 += n + 1;
		if (token2[0] == '\0')
			token2 = NULL;
	}
	return (token1);
}


/**
 * tokenize - tokenize string
 * @str: string
 * @built_in: check builitn func
 *
 * Return: array of tokens
 */
char **tokenize(char *str, int built_in)
{
	char *token = NULL, *flag = NULL, **arr = NULL;
	int size = 0, n = 0;
	struct stat st = {0};

	size = args(str);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);

	token = _strtok(str, ' ');
	while (token != NULL)
	{
		arr[n] = _strdup(token);
		token = _strtok(NULL, ' ');
		n++;
	}

	if (built_in == 0 && arr[0][0] != '/')
	{
		flag = path(arr[0]);
		if (flag != NULL)
		{
			free(arr[0]);
			arr[0] = _strdup(flag);
		}
		else
		{
			if ((stat(arr[0], &st) == 0) || (file_dir(arr[0]) == 0))
				;
			else
				perror(arr[0]);
		}
		free(flag);
	}
	arr[n] = NULL;

	return (arr);
}


/**
 * clean_str - removes '\n' and '\t'
 * @str: str/buffer
 * @count: len of str
 *
 * Return: cleaned str
 */
char *clean_str(char *str, int count)
{
	str[count - 1] = '\0';
	str = searchAndDestroy(str);
	str = comments(str);
	return (str);
}
