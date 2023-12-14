#include "monty.h"

/**
 * _mul - multiplies second top elems
 * @stack: the stack
 * @ln: line number
 */

void _mul(stack_t **stack, unsigned int ln)
{
	int product;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "mul");
		return;
	}

	*stack = (*stack)->next;

	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mod - computes the rest of the division of the second top elems
 * @stack: the stack
 * @ln: line numer
 */
void _mod(stack_t **stack, unsigned int ln)
{
	int remainder;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "mod");
		return;
	}

	if ((*stack)->n == 0)
	{
		more_error(9, ln);
		return;
	}

	*stack = (*stack)->next;

	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * _pchar - print the  char
 * @stack: the stack
 * @ln: line number
 */
void _pchar(stack_t **stack, unsigned int ln)
{
	int character_code;

	if (!stack || !*stack)
	{
		str_error(11, ln);
		return;
	}

	character_code = (*stack)->n;

	if (character_code < 0 || character_code > 127)
	{
		str_error(10, ln);
		return;
	}

	printf("%c\n", character_code);
}
/**
 * _pstr - print the string starting at top
 * @stack: the stack
 * @ln: line number
 */
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *current_node;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	current_node = *stack;

	while (current_node != NULL)
	{
		int character_code = current_node->n;

		if (character_code <= 0 || character_code > 127)
			break;

		printf("%c", character_code);
		current_node = current_node->next;
	}

	printf("\n");
}

/**
 * _rotl - rotate the stack to top
 * @stack: the stack
 * ln: line number
 */
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	 stack_t *current_node;

	if (!stack || !*stack || !(*stack)->next)
		return;

	current_node = *stack;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	(*stack)->prev = current_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

