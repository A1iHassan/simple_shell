#include "monty.h"

/**
 * _swap - swap top 2 elems
 * @stack: the stack
 * @ln: line num
 */
void _swap(stack_t **stack, unsigned int ln)
{
	 stack_t *first_node;
	 stack_t *second_node;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "swap");
		return;
	}

	first_node = *stack;
	second_node = first_node->next;

	first_node->next = second_node->next;

	if (second_node->next)
		second_node->next->prev = first_node;

	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;

	*stack = second_node;
}

/**
 * _add - add top 2 elems
 * @stack: stack
 * @ln: line number
 */

void _add(stack_t **stack, unsigned int ln)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "add");
		return;
	}

	*stack = (*stack)->next;

	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _sub - substrac the top elems
 * @stack: the stack
 * @ln: line number
 */

void _sub(stack_t **stack, unsigned int ln)
{
	int difference;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "sub");
		return;
	}

	*stack = (*stack)->next;

	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * _nop - do nothing
 * @stack: stack
 * @ln: line number
 */
void _nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 * _div - divide the second top elems
 * @stack: stack
 * @ln: line numbers
 */
void _div(stack_t **stack, unsigned int ln)
{
	int quotient;

	if (!stack || !*stack || !(*stack)->next)
	{
		more_error(8, ln, "div");
		return;
	}

	if ((*stack)->n == 0)
	{
		more_error(9, ln);
		return;
	}

	*stack = (*stack)->next;

	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}




