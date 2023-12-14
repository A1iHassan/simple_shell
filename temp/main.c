#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: num of args
 * @argv: numsvactor
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1]);
	_free();
	return (0);
}

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
		_error(4);
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

	if (head == NULL)
		return;

	while (head != NULL)
	{
		q = head;
		head = head->next;
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
	if (head == NULL)
	{
		head = *new;
		return;
	}
	q = head;
	while (q->next != NULL)
		q = q->next;

	q->next = *new;
	(*new)->prev = q;

}
