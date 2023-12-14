#include "monty.h"

/**
 * _open - open file
 * @file: the file namepath
 * Return: void
 */

void _open(char *file)
{
	FILE *dn = fopen(file, "r");

	if (file == NULL || dn == NULL)
		_error(2, file);
	_read(dn);
	fclose(dn);
}


/**
 * read_file - reads a file
 * @dn: pointer to file descriptor
 * Return: void
 */

void _read(FILE *dn)
{
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buffer, &len, dn) != -1; ln++)
	{
		format = _parse(buffer, ln, format);
	}
	free(buffer);
}



int _parse(char *buff, int ln, int ft)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		_error(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (ft);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_d(opcode, value, ln, ft);
	return (ft);
}
/**
 * func_d - call function to execute
 * @opcode: the obcode
 * @value: value
 * @ln: line number
 * @ft: format
 */
void func_d(char *opcode, char *value, int ln, int ft)
{
	int i;
	int sign;
	instruction_t sort_fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	for (sign = 1, i = 0; sort_fun[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, sort_fun[i].opcode) == 0)
		{
		c_func(sort_fun[i].f, opcode, value, ln, ft);
			sign = 0;
		}
	}
	if (sign == 1)
		_error(3, ln, opcode);
}

void c_func(op_func func, char *op, char *val, int ln, int ft)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				_error(5, ln);
		}
		node = made_node(atoi(val) * flag);
		if (ft == 0)
			func(&node, ln);
		if (ft == 1)
			put_queue(&node, ln);
	}
	else
		func(&head, ln);
}
