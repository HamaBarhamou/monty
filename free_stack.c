#include "main.h"

/**
 * free_stack_t - function that free a list of type dlistint_t
 * @head: pointer to a list type stack_t
 *
 * Return: void.
 */
void free_stack_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
