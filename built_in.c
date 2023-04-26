#include "main.h"

/**
 * hsh_exit - implement the exit built-in and others
 * @argv: argument
 *
 * Return: void
 */
void hsh_exit(__attribute__((unused))char **argv)
{
	exit(0);
}


/**
 * hsh_cd - implement the change directory built-in
 * @argv: argument
 *
 * Return: void
 */
void hsh_cd(char **argv)
{
	if (argv[1] == NULL)
		perror("cd error");
	if (chdir(argv[1]) != 0)
		perror("some other cd error");
}


/**
 * hsh_help - print help information
 * @argv: argument
 *
 * Return: void
 */
void hsh_help(__attribute__((unused))char **argv)
{
	char info[] =
		"ALX Simple Shell Project\n"
		"Available Commands:\n"
		"\tcd: Change the working directory.\n"
		"\texit: Exit shell.\n"
		"\thelp: Print this infomation.\n"
		;
	printf("%s", info);
}


/**
 * struct builtin - struct
 *
 * Description: registering the association between
 * a command name and its handler function
 */
struct builtin builtins[] = {
	{
		"help",	hsh_help
	},
	{
		"exit",	hsh_exit
	},
	{
		"cd", hsh_cd
	},
};


/**
 * num_builtins - handler function for struct builtin
 *
 * Return: size
 */
int num_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}
