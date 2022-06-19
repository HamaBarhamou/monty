#include "monty.h"


/**
 * _push - function push an element to the stack
 * @pile: the pile
 * @line_number: the number
 * Return: void
 */

void  _push(stack_t **pile, unsigned  int line_number)
{
	int nb;


	if (arguments == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	nb = atoi(arguments);
	/*printf("push: %d\n",atoi(arguments));*/
	if (arguments[0] != '0' && nb == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_node(pile, atoi(arguments));
	UNUSED(pile);
	UNUSED(line_number);
}
