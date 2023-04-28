#include "main.h"

/**
 * is_digit - check if string is made of numbeers
 * @str: string
 *
 * Return: status - is int?
 */
int is_digit(char *str)
{
	int i = 0, flag = 0;

	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
		{
			i++;
			continue;
		}
		else
		{
			flag++;
			break;
		}
	}
	return (flag);
}


/**
 * comment_hash - checks for cmmmts markers
 * @str: String to traverse
 *
 * Return: str without comments
*/
char *comment_hash(char *str)
{
	int i = 0, j, hashtag = 0, flag = 0;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == ' ' && str[j + 1] == '#')
		{
			hashtag++;
			break;
		}
	}
	if (hashtag == 0)
		return (str);
	while (str[i])
	{
		if (flag == 1)
		{
			str[i] = ' ';
			i++;
			continue;
		}
		if (str[i] == ' ' && str[i + 1] == '#')
		{
			flag++;
			i++;
			continue;
		}
		i++;
	}
	return (str);
}


/**
 * rm_tab - removes tabs - '\t'
 * @str: str
 *
 * Return: str without tab
 */
char *rm_tab(char *str)
{
	int i, tab = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\t')
			tab++;
	}
	i = 0;
	if (tab > 0)
	{
		while (str[i])
		{
			if (str[i] == '\t')
				str[i] = ' ';
			i++;
		}
	}
	return (str);
}


/**
 * sig_handler - signal handler
 * @signum: signal num
 *
 * Return: void
 */
void sig_handler(__attribute__((unused))int signum)
{
	write(STDOUT_FILENO, "\n$ ", 4);
}


/**
 * argc - argument count
 * @str: string
 *
 * Return: count of args
 */
int argc(char *str)
{
	int i = 1, count = 0;

	if (str[0] != ' ')
		count++;

	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		count++;

	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			count++;
		i++;
	}

	return (count);
}
