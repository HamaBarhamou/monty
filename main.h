#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUF_SIZE 9096
#define LINE 1000

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct linefile_s - struct of line file
 * @opcode: the opcode
 * @arg: the opcode arguments
 */
typedef struct linefile_s
{
	char *opcode;
	char *arg;
} linefile_t;

extern char *arguments;

void _puts(char *str);
int _putchar(char c);
void  _add(stack_t **pile, unsigned  int line_number);
void  _div(stack_t **pile, unsigned  int line_number);
void  _mod(stack_t **pile, unsigned  int line_number);
void  _mul(stack_t **pile, unsigned  int line_number);
void  _nop(stack_t **pile, unsigned  int line_number);
void  _pall(stack_t **pile, unsigned  int line_number);
void  _pint(stack_t **stack, unsigned  int line_number);
void  _pop(stack_t **pile, unsigned  int line_number);
void  _push(stack_t **pile, unsigned  int line_number);
void  _sub(stack_t **pile, unsigned  int line_number);
void  _swap(stack_t **pile, unsigned  int line_number);
void  _pchar(stack_t **pile, unsigned  int line_number);
void  _pstr(stack_t **pile, unsigned  int line_number);
void  _rotr(stack_t **pile, unsigned  int line_number);
void  _rotl(stack_t **pile, unsigned  int line_number);
void  _stack(stack_t **pile, unsigned  int line_number);
void  _queue(stack_t **pile, unsigned  int line_number);

/**
 * get_opcode - reads opcode and verifies if is valid.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * @code: code to operate.
 *
 * Return: void.
 */

void get_opcode(stack_t **stack, unsigned int line_number, char *code);
void add_node(stack_t **stack, int argument);
void add_node_queue(stack_t **stack, int argument);
void free_stack_t(stack_t *head);
void add_node_queue(stack_t **stack, int argument);
linefile_t *get_opcode_and_arg(char *str);

#endif
