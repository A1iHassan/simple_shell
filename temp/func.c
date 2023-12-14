#include "monty.h"

int _parse(char *buff, int ln, int ft)
{
	char *opcode;
	char *value;
	const char *delim = "\n ";

	if (buff == NULL)
		fprintf(stderr, "Error: malloc failed\n");

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
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
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
				fprintf(stderr, "L%d: usage: push integer\n", ln);
		}
		node = made_node(atoi(val) * flag);
		if (ft == 0)
			func(&node, ln);
		if (ft == 1)
			put_queue(&node, ln);
	}
	else
		func(&top, ln);
}

/**
 * _rotr - rotate the stack to the bottom
 * @stack: the stack
 * @ln: line number
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *current_node;

	if (!stack || !*stack || !(*stack)->next)
		return;

	current_node = *stack;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	current_node->prev->next = NULL;
	current_node->prev = NULL;

	(*stack)->prev = current_node;
	*stack = current_node;
}
