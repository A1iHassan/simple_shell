#include "monty.h"

/**
 * _push - push integer into stack
 * @new: new node
 * @ln: line number
 */
void _push(stack_t **new, __attribute__((unused))unsigned int ln)
{
	if (!new || !*new)
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *new;
		return;
	}

	(*new)->next = head;
	head->prev = *new;
	head = *new;
}
/**
 * _pall - prinr num from stack
 * @stack: stack
 * @ln: line num
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *currentNode;

	(void)ln;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	currentNode = *stack;

	while (currentNode != NULL)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next;
	}
}
/**
 * _pint - print last num
 * @stack: the stack
 * @ln: line number
 */

void _pint(stack_t **stack, unsigned int ln)
{
	if (!stack || !*stack)
		_error(6, ln);
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - remove top elements
 * @stack: the stack
 * @ln: line number
 */
void _pop(stack_t **stack, unsigned int ln)
{
	stack_t *q;
	if (stack == NULL || *stack == NULL)
		more_error(7, ln);
	q = *stack;
	*stack = q->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(q);
}
