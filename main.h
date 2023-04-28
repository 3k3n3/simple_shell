#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/*String formatting operations*/
int _strlen(const char *s);
int _atoi(char *s);
int is_digit(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strtok(char *str, char delim);
char **tokenize(char *str, int builtin);
char *clean_str(char *str, int counter);

/*Checks builin functions, path & env*/
void print_env(void);
int check_cd(char *str);
int check_hash(char *str);
int check_env(char *str);
int check_builtin(char *str);
int check_exit(char *str);
int check_unsetenv(char *str);
int check_setenv(char *str);
int set_env(char *name, char *value, int overwrite);
int unset_env(char *name);
char *path(char *filename);
char *get_env(const char *name);
char *create_var(char *name, char *value);

void isatty_signal(void);
void sig_handler(int signum);
int argc(char *str);
int is_exec(char *str);
int file_dir(const char *fileName);
int get_return_val(char *str);
int child_fork(pid_t child_pid, char *name);
char *comment_hash(char *str);
char *rm_tab(char *str);

/*Free envs and memory*/
void wait_free(int status, char **argv, char *dup);
void free_array_dup(char **arr, char *dup);
void free_exit(char *str);
void free_env(char *var);
void free_buff_env(char *str);

#endif/*MAIN_H*/
