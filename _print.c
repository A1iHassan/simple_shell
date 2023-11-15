#include "shell.h"

/**
 * _print - prints out a given string
 * @user_input: given string's pointer
 */

void _print(char *user_input)
{
	write(STDOUT_FILENO, user_input, _strlen(user_input));
}
