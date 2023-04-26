#include "main.h"

/**
 * hsh_exit - implement the exit built-in and others
 * @argv: argument
 *
 * Return: void
 */
void hsh_exit(char **argv)
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
 * @argv: argument/command
 *
 * Return: void
 */
void hsh_help(char **argv)
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

struct builtin builtins[] = {
	{"help", hsh_help},
	{"exit", hsh_exit},
	{"cd", hsh_cd},
};

int num_builtins = sizeof(builtins) / sizeof(struct builtin);
