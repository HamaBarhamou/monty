#include "monty.h"


/**
 * _swap - function
 * @stack: the pile
 * @line_number: the number
 * Return: void
 */

void  _swap(stack_t **stack, unsigned  int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next)
		((*stack)->next)->prev = temp;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
}
