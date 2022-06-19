#include "monty.h"


/**
 * get_opcode_and_arg - function
 * @str: the chaine
 *
 * Return: the linefile_t objet
 */
linefile_t *get_opcode_and_arg(char *str)
{
	linefile_t *t = malloc(sizeof(linefile_t));
	char *token = strtok(str, " \t\r\f\n\v");


	t->opcode = token;
	/*printf("token: %s\n",token);*/
	token = strtok(NULL, " \t\r\f\n\v");
	/*printf("token: %s\n",token);*/
	t->arg = token;

	return (t);
}
