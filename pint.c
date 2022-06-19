#include "monty.h"


/**
 * _pint - function
 * @pile: the pile
 * @line_number: the number
 * Return: void
 */

void  _pint(stack_t **pile, unsigned  int line_number)
{
	if (*pile == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack_t(*pile);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*pile)->n);
	UNUSED(line_number);
}
