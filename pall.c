#include "monty.h"


/**
 * _pall - function
 * @pile: the pile
 * @line_number: the number
 * Return: void
 */

void  _pall(stack_t **pile, unsigned  int line_number)
{
	stack_t *ptr;

	ptr = *pile;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	UNUSED(line_number);
}
