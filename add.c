#include "monty.h"

/**
 * _add - function
 * @stack: the pile
 * @line_number: the number
 * Return: void
 */

void  _add(stack_t **stack, unsigned  int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
