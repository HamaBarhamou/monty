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


#define BUF_SIZE 9096
#define LINE 100

/**
* main - function
*
* @argv: the chaine of chaine
* @argc: the int
* Return: Always 0.
*/

int main(int argc, char **argv)
{
	char *filename, buf[BUF_SIZE + 1];
	int fp, ret, nbLine = 1;

	if (argc != 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		fprintf(stderr, "%s", "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	while ((ret = read(fp, buf, LINE)))
	{
		buf[ret] = '\n';
		_puts(buf);
		nbLine++;
	}

	close(fp);
	exit(EXIT_SUCCESS);
}
