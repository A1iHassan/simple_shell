#include "monty.h"

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

