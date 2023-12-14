#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include<unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;
typedef void (*op_func)(stack_t **, unsigned int);

void put_queue(stack_t **, unsigned int);
void _free(void);
stack_t *made_node(int n);
void _push(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
void _pstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);
int _parse(char *buff, int ln, int ft);
void func_d(char *opcode, char *value, int ln, int ft);
void c_func(op_func func, char *op, char *val, int ln, int ft);
void _error(int err, ...);
void more_error(int err, ...);
void str_error(int err, ...);
ssize_t getline(char **a, size_t *b, FILE *c);

#endif
