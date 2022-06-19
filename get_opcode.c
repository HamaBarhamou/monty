#include "monty.h"

/**
 * get_opcode - reads opcode and verifies if is valid.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 * @code: opcode to excecute.
 *
 * Return: void.
 */
void get_opcode(stack_t **stack, unsigned int line_number, char *code)
{
	int i = 0;
	instruction_t opcode_func[] = {
		{"add", _add},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul},
		{"nop", _nop},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"push", _push},
		{"sub", _sub},
		{"swap", _swap},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotr", _rotr},
		{"rotl", _rotl},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	while (opcode_func[i].opcode)
	{
		if (strcmp(opcode_func[i].opcode, code) == 0)
		{
			opcode_func[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u %s %s", line_number, ": unknown instruction\n", code);

	/*free_stack_t(*stack);*/

	exit(EXIT_FAILURE);
}

