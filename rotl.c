#include "monty.h"


/**
 * _rotl - function
 * @stack: the pile
 * @line_number: the number
 * Return: void
 */

void  _rotl(stack_t **stack, unsigned  int line_number)
{
	stack_t *temp, *last;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}
