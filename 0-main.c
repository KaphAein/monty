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
	char *file_extension;
	int n = 0, i;
	FILE *fd;
	size_t bufsize = 1000;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_extension = strrchr(av[1], '.');
	if (file_extension == NULL || strcmp(file_extension, ".m") != 0)
	{
		fprintf(stderr, "Error: Invalid file extension. The file must have a \".m\" extension.\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (n = 0; n < MAX_LINES && fgets(string[n], bufsize, fd) != NULL; n++)
	{
		string[n] = malloc(bufsize);
		if (string[n] == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}
	execute(string, stack);
	for (i = 0; i < n; i++)
		free(string[i]);
	fclose(fd);
	return (0);
}
