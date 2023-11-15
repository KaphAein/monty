#include "main.h"
#include <stdio.h>

#define MAX_LINES 1000

/**
 * main - interperter
 * @ac: number of arguments
 * @av: argument string
 * Return: 0 success
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	static char *string[MAX_LINES] = {NULL};
	int n = 0;
	FILE *fd;
	size_t bufsize = 1000;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}


	while (n < MAX_LINES && fgets(string[n], bufsize, fd) != NULL)
	{
		n++;
	}
	execute(string, stack);
	free_list(string);
	fclose(fd);
	return (0);
}
