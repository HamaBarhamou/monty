#include "monty.h"



/**
 * _rotr - function
 * @stack: the pile
 * @line_number: the number
 * Return: void
 */

void  _rotr(stack_t **stack, unsigned  int line_number)
{
	stack_t *temp, *last;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	temp = *stack;
	*stack = last;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = temp;
	temp->prev = *stack;
}
