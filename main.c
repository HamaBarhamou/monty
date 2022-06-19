/*****************************************************************************/
/*                                                                           */
/*                                               _____  ______    ____  ___  */
/* 0-puts_recursion.c                           /  _  \ |    |    \   \/  /  */
/*                                             /  /_\  \|    |     \     /   */
/* By: Barahmou   <hamabarhamou@gmail.com>    /    |    \    |___  /     \   */
/*                                            \____|__  /_______ \/___/\  \  */
/* Created: 2022-03-30 09:46:22   $Barahmou           \/        \/      \_/  */
/* Updated: 2022-03-30 09:46:22 by Barahmou                                  */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "monty.h"

char *arguments = NULL;

/**
* main - function
*
* @argv: the chaine of chaine
* @argc: the int
* Return: Always 0.
*/

int main(int argc, char **argv)
{
	char *filename, line[BUF_SIZE + 1], *code = NULL;
	int nbLine = 1;
	FILE *fp;
	stack_t *stack = NULL;
	linefile_t *op = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "%s", "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	arguments = NULL;
	while (fgets(line, LINE, fp) != NULL)
	{
		op  = get_opcode_and_arg(line);
		arguments = op->arg;
		/*code = strtok(line, " \t\r\v\f\n");*/
		/*printf("co: %s op:  %s \n",code,opcode_arg->opcode);*/
		if (op->opcode != NULL && op->opcode[0] != '#' && op->opcode[0] != '\n')
			get_opcode(&stack, nbLine, op->opcode);
		/*_puts(line);*/
		nbLine++;
	}

	UNUSED(stack);
	UNUSED(code);
	UNUSED(arguments);
	free_stack_t(stack);
	fclose(fp);
	exit(EXIT_SUCCESS);
}
