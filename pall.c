#include "monty.h"
/**
 *pall - Function that display the stack content
 *@stack: reffer to main function
 *@line_counter: number of line
 *
 *return: void
 */

void pall(stack_t **stack, unsigned int line_counter __attribute__((unused)))
{
print_stack(*stack);
}
