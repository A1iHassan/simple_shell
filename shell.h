#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include <sys/wait.h>

int more_built(char *line, char **envp, int *status);
int comp_built(char *line, int *status);
void cd_old(char *dir);
void _old(void);
void execute_command(const char *command);
char *execute(char *command);
int execmd(char **argv, char **envp);
char *get_oldpwd();
void _print(char *user_input);
char *_strcpy(char *dest, char *src);
size_t _strlen(const char *s);
char *_strdup(const char *str);
void _exit_(void);
unsigned int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
void _envp_(char **envp);
int built_in(char *line, int *status);
int is_stat(char *line);
void cd_home(char *dir);
void handle_set(char **args);
void handel_unset(char **args);
void _setenv(char *var, char *val);
void _unsetenv(char *var);
char *_strcat(char *s1, char *s2);
void is_dir(char *line, char **envp, char **a);
int count(char *line);
char **tokenize_se(char *line);
char **tokenize(char *line);
void _cd(void);
size_t _strlen_(char **s);
char *_hash(char *line);
void _free(char **grid, int height);
int _echo(char *line, int *status);
char *_strchr(char *s, char c);
#endif
