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
#include "main.h"



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
	stack_t *stack =NULL;

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

	while (fgets(line, LINE, fp) != NULL)
	{
		code = strtok(line, " \t\r\v\f\n");
		if (code != NULL && code[0] != '#')
			get_opcode(&stack, nbLine, code);
		/*_puts(line);*/
		nbLine++;
	}

	printf("nb=%d", nbLine);
	fclose(fp);
	exit(EXIT_SUCCESS);
}
