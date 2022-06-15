#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#include "monty.h"


/**
 *push - function that add element at the end of the stack
 *
 *@stack: refer to the main
 *@counter: number of the total line
 *
 *Return: always either success with exit code o or failed with exit code 1
 */

void push(stack_t **stack, unsigned int counter)
{
char *n = global.argument;
if ((is_digit(n)) == 0)
{
fprintf(stderr, "L%d: usage: usage: push integer\n", counter);
exit(EXIT_FAILURE);
}
if (global.data_struct == 1)
{
if (!add_node(stack, atoi(global.argument)))
{
exit(EXIT_FAILURE);
}
}
else
{
if (!queue_node(stack, atoi(global.argument)))
{
exit(EXIT_FAILURE);
}
}
}
