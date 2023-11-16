#include "shell.h"

/**
 * count - calculates the number of words in a string
 * @line: string pointer
 * Return: words number
 */

int count(char *line)
{
	char *holder = line, *holder2 = line;
	int count = 0, count2 = 0;

	while (*holder2)
	{
		if (*holder2 != ' ' && *holder2 != '\n' &&
				*holder2 != '\0' && *holder2 != '\t')
		{
			count2 = 1;
			break;
		}
		holder2++;
	}
	if (count2 == 0)
		return (0);
	while (*holder)
	{
		if ((*holder == ' ' || *holder == '\n' || *holder == '\t') &&
				(*(holder + 1) != ' ' && *(holder + 1) != '\n' &&
				 *(holder + 1) != '\0' && *(holder + 1) != '\t'))
		{
			count++;
		}
		holder++;
	}
	count++;
	return (count);
}
/**
 * tokenize - tokenize command
 * @line: the line
 * Return: array
 */
char **tokenize(char *line)
{
	int  i = 0, j = 0, k, l = count(line);
	char *holder = line;
	char **arr = malloc(sizeof(char *) *(l + 1));

	if (!arr)
	{
/*		free(arr);*/
		exit(-1); }
	while (*holder)
	{
		while ((*(holder) != ' ' && *(holder) != '\n' &&
					*(holder) != '\0' && *(holder) != '\t'))
		{
			i++;
			holder++;
		}
		if (i > 0)
		{
			arr[j] = malloc(sizeof(char) * i + 1);
			if (!arr[j])
			{
				for (i = 0; i <= j; i++)
				{
					free(arr[i]);
				}
				free(arr);
				exit(-1);
			}
			for (k = 0; k < i; k++)
			{
				arr[j][k] = *(holder - i + k);
			}
			arr[j][k] = '\0';
			j++;
			i = 0;
		}
			holder++;
	}

	arr[j] = NULL;
	return (arr);
}
