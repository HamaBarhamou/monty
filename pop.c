#include "monty.h"


/**
 * _pop - function
 * @pile: the pile
 * @line_number: the number
 * Return: void
 */

void  _pop(stack_t **pile, unsigned  int line_number)
{
	stack_t *ptr;

	if (*pile == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack_t(*pile);

		exit(EXIT_FAILURE);
	}

	ptr = *pile;
	if ((*pile)->next)
		(*pile)->next->prev = NULL;
	*pile = (*pile)->next;
	free(ptr);
	UNUSED(line_number);
}
