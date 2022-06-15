#ifndef MONTY_H
#define MONTY_H

#include "stddef.h"
#include "stdlib.h"

#define INSTRUCTIONS
{
{"push", push}
}

/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: track the previous element in the stack (or queue)
 *@next: track the next element in the stack (or queue)
 */

typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
}stack_t;

/**
 *struct instruction_s - opcode and it function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 */
typedef struct instruction_s
{
char *opcode;
void(*f)(stack_t **stack, unsigned int line_counter);
} instruction_t;

/**
 *struct help - argument for the current opcode
 *@data_strcut: stack mode, stack and queue
 *@argument: the argument
 *
 */
typedef struct help
{
int data_struct;
char argument;
} help;
help global;

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

void push(stack_t **stack, unsigned int line_count);

void opcode(stack_t **stack, char *str, unsigned int line_count);

int is_digit(char *string);
int isnumber(char *str);

#endif /*MONTY_H*/
