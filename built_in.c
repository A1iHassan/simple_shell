#include "shell.h"
#include<unistd.h>
#include <sys/stat.h>

int  comp_built(char *line);
/**
 * built_in - checks for built in commands to be executed
 * @line: give input string
 * Return: 1 sometimes
 */

int built_in(char *line)
{
	char **a = NULL;
	int count = 0;
	int exit_status;

	a = tokenize(line);
	count = _strlen_(a);

	if (_strcmp(a[0], "exit") == 0)
	{
		if (count == 1)
		{
			free(line);
			_free(a, _strlen_(a));
			exit(0); }
		else if (count == 2)
		{
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
		else
		{
			_free(a, _strlen_(a));

		return (1); }
	}
	else
	{
		_free(a, count); }
	return (0);
}
/**
 * comp_built - check if command built in
 * @line: the line
 * Return: 0 or 1
 */
int  comp_built(char *line)
{
	char **a = NULL;
	int count = 0;
	char *dir = getenv("HOME");
	char *text = "./hsh: 1: cd: can't cd to ";

	a = tokenize(line);
	count = _strlen_(a);

	if (_strcmp(a[0], "cd") == 0)
	{
		if (count == 1)
		{
			chdir(dir);
			_cd();
			_free(a, _strlen_(a));
			return (1); }
		else if (count == 2 && _strcmp(a[1], "-") == 0)
		{
			cd_old(dir);
			_free(a, _strlen_(a));
			return (1);
		} else if (count == 2)
		{
			if (chdir(a[1]) == 0)
			{
				_cd();
				_free(a, _strlen_(a));
				return (1);
			}
			else
			{
				write(2, text, _strlen(text));
				write(2, a[1], _strlen(a[1]));
				write(2, "\n", 1);
				_free(a, _strlen_(a));
				return (1); } } }
	else
	{
		_free(a, count); }
	return (0); }
/**
* more_built - check if command is built in
* @line: the line
* Return: 0 or 1
*/
int more_built(char *line)
{
	char **a = NULL;
	int count = 0;

	a = tokenize(line);
	count = _strlen_(a);

	if (_strcmp(a[0], "unsetenv") == 0)
	{
		handel_unset(a);
		_free(a, _strlen_(a));
		return (1); }
	else if (_strcmp(a[0], "setenv") == 0)
	{
		handle_set(a);
		_free(a, count);
		return (1); }
	else if (_strcmp(a[0], "env") == 0)
	{
		_envp_();
		_free(a, _strlen_(a));
	}
	else
	{       execmd(a);
		_free(a, count);
	}
	return (0);
}
