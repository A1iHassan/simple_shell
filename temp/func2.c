#include "monty.h"

/**
 * made_node - make new node
 * @n: num in the node
 * Return: null
 */
stack_t *made_node(int n)
{
	stack_t *add;

	add = malloc(sizeof(stack_t));
	if (add == NULL)
		fprintf(stderr, "Error: malloc failed\n");
	add->next = NULL;
	add->prev = NULL;
	add->n = n;
	return (add);
}

/**
 * _free - Frees nodes in the stack.
 */
void _free(void)
{
	stack_t *q;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		q = top;
		top = top->next;
		free(q);
	}
}


/**
 * put_queue - insert new node into queue
 * @new: Pointer
 * @ln: line number
 */
void put_queue(stack_t **new, __attribute__((unused))unsigned int ln)
{
	stack_t *q;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (top == NULL)
	{
		top = *new;
		return;
	}
	q = top;
	while (q->next != NULL)
		q = q->next;

	q->next = *new;
	(*new)->prev = q;

}
