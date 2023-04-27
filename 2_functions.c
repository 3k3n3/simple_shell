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
 * comments - Checks for comments
 * @str: String to traverse
 *
 * Return: The clean string in case of comments, if not, the same one
 */
char *comments(char *str)
{
	int i = 0, j = 0, hashtag = 0, flag = 0;

	while (str[j])
	{
		if (str[j] == ' ' && str[j + 1] == '#')
		{
			hashtag++;
			break;
		}
		j++;
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
 * searchAndDestroy - Looks for a tabulation and erases it
 * @str: String to traverse
 *
 * Return: The modified string or just the string
 */
char *searchAndDestroy(char *str)
{
	int i = 0, tab = 0;

	while (str[i])
	{
		if (str[i] == '\t')
		{
			tab++;
		}
		i++;
	}
	i = 0;
	if (tab > 0)
	{
		while (str[i])
		{
			if (str[i] == '\t')
			{
				str[i] = ' ';
			}
			i++;
		}
	}
	return (str);
}
