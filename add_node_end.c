#include "monty.h"


/**
 * add_node_queue -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @argument: integer push.
 *
 * Return: void.
 */
void add_node_queue(stack_t **stack, int argument)
{
	stack_t *new_node = NULL, *last = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		new_node->next = NULL;
		new_node->prev = last;
		last->next = new_node;
	}
}
