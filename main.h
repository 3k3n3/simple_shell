#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **split_line(char *line, ssize_t nread);
void exec(char **argv);
void hsh_exit(char **argv);
void hsh_cd(char **argv);
void hsh_help(char **argv);
char *_strcpy(char *line_cpy, char *line);
int _strcmp(char *str1, char *str2);

/**
 * struct builtin - register association btw cmd and handler
 * @name: name of function
 * @func: function
 */
struct builtin
{
	char *name;
	void (*func)(char **argv);
};

extern struct builtin builtins[];
extern int num_builtins;
/*extern int num_builtins = sizeof(builtins) / sizeof(struct builtin);*/

#endif/*MAIN_H*/
