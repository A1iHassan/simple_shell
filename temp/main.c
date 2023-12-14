#include "monty.h"
stack_t *top = NULL;

/**
 * main - entry point
 * @argc: num of args
 * @argv: numsvactor
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *dn = fopen(argv[1], "r");
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	if (argv[1] == NULL || dn == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);

	for (ln = 1; getline(&buffer, &len, dn) != -1; ln++)
		format = _parse(buffer, ln, format);
	free(buffer);
	fclose(dn);
	_free();
	return (0);
}
