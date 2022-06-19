#include "monty.h"
#include <stddef.h>

/**
 * get_intr_func - a function
 * @s: the instruction
 *
 * Return: chaine
 */
void (*get_intr_func(char *s))(stack_t **stack, unsigned int line_number)
{
	UNUSED(s);
	return (NULL);
}
