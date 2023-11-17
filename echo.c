#include "shell.h"

/**
 * _str - converts an int to char *
 * @a: the int
 * Return: the final string
 */
char *_str(int a)
{
	int i = 0, j;
	char *res = NULL;

	if (a == 0)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';
		return (res); }
	while (a / 10 != 0 || a % 10 != 0)
	{
		i++;
		a /= 10; }
	res = malloc((i + 1) * sizeof(char));
	if (!res)
	{
		free(res);
		return (NULL); }
	for (j = 1; j <= i; j++)
	{
		res[i - j] = ((a % 10) + '0');
		a /= 10; }
	res[i] = '\0';
	return (res);
}

/**
 * _echo - performs echo $$ and echo $?
 * @line: the input command line
 * @status: current process status
 * Return: a value of int
 */
int _echo(char *line, int *status)
{
	char **a = tokenize(line);
	char *msg;

	if (a == NULL)
	{
		free(a);
		return (0);
	}
	if (_strcmp(a[0], "echo") == 0)
	{
		if (_strcmp(a[1], "\\$?") == 0)
		{
			msg = _str(*status);
			write(1, msg, _strlen(msg));
			write(1, "\n", 1);
			free(msg);
			_free(a, _strlen_(a));
			return (1);
		}
		else if (_strcmp(a[1], "\\$\\$") == 0)
		{
			msg = _str(getpid());
			write(1, msg, _strlen(msg));
			write(1, "\n", 1);
			free(msg);
			_free(a, _strlen_(a));
			return (1);
		} }
	_free(a, _strlen_(a));
	return (0);
}
