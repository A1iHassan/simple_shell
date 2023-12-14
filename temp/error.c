#include "monty.h"
/**
 * _error: handle errors
 * @err: the errors
 */
void _error(int err, ...)
{
	va_list arg;
	char *op;
	int line;

	va_start(arg, err);
	switch (err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
/**
 * more_error - continue handling
 * @err: errors
 */
void more_error(int err, ...)
{
	va_list arg;
	char *op;
	int line;

	va_start(arg, err);
	switch (err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			line = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}

/**
 * str_error - handle the error
 * @err: The errors
 */
void str_error(int err, ...)
{
	int line;
	va_list arg;;

	va_start(arg, err);
	line = va_arg(arg, int);
	switch (err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
