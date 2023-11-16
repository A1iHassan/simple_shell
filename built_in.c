#include "shell.h"
#include<unistd.h>
#include <sys/stat.h>

/**
 * built_in - checks for built in commands to be executed
 * @line: give input string
 * Return: 1 sometimes
 */

int built_in(char *line, char **envp)
{
	char **a = NULL;
	int i = 0;
	int count = 0;
	char *previous_dir = getenv("OLDPWD");
	char *dir = getenv("HOME");
	char *pwd = getenv("PWD");
	char *text = "./hsh: 1: cd: can't cd to ";
	int exit_status;
	a = tokenize(line);
	count = _strlen_(a);

	(void)previous_dir,(void)i; (void)pwd;
	if (_strcmp(a[0], "exit") == 0)
	{
		if (count == 1){
			free(line);
			_free(a, _strlen_(a));
			exit(0);
		}
		else if (count == 2) {
			exit_status = atoi(a[1]);
			if (exit_status < 0 || (exit_status == 0 && a[1][0] != '0'))
			{ 
				write(STDERR_FILENO, "./hsh: 1: exit: ", 16);
				write(STDERR_FILENO, "Illegal number: ", 16);
				write(STDERR_FILENO, a[1], _strlen(a[1]));
				write(2, "\n", 1);
				free(line);
				_free(a, _strlen_(a));
				exit(2); } 
			else 
			{ 
				free(line);
				_free(a, _strlen_(a));
				exit(exit_status); }

		}
		else {
			_free(a, _strlen_(a));


			return (1); 
		}
	}
/**	else if (_strcmp(a[0], "env") == 0)
	{
		_envp_();
		_free(a, _strlen_(a));
		return (1);
	}*/ else if (_strcmp(a[0], "cd") == 0)
	{
		if (count == 1)
		{
			chdir(dir);
			_cd();
			_free(a, _strlen_(a));
			return (1); }
		else if (count == 2 && _strcmp(a[1], "-") == 0)
		{
			chdir(dir);
			_cd();
			_free(a, _strlen_(a));
			return (1);
		} else if (count == 2)
			if (chdir(a[1]) == 0)
			{
				_cd();
				_free(a, _strlen_(a));
				return (1);
			} else
			{
				write(2, text, _strlen(text));
				write(2, a[1], _strlen(a[1]));
				write(2, "\n", 1);
				_free(a, _strlen_(a)); 
				return (1); }
			else 
			{
				write(2, text, _strlen(text));
				write(2, a[1], _strlen(a[1]));
				write(2, "\n", 1);
				_free(a, _strlen_(a));
				return (1); } }
	else if (_strcmp(a[0], "setenv") == 0)
	{
		handle_set(a);
		_free(a, count);
		return (1); }
	else if (_strcmp(a[0], "unsetenv") == 0)
	{
		handel_unset(a);
		_free(a, _strlen_(a));	
		return (1); }
	else
	{	execmd(a, envp);
		_free(a, count);
	}

	
	return (0);
}
