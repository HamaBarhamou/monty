#include "monty.h"


/**
 * _pchar - function
 * @stack: the pile
 * @line_number: the number
 * Return: void
 */

void  _pchar(stack_t **stack, unsigned  int line_number)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n >= 32 && n <= 127)
		printf("%c\n", n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}
}
