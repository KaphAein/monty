#include "main.h"

/**
 * _strcmp - compares strings
 * @opcode: a string to be compared
 * @list: a string to be compared
 * Return: 0
 */
int _strcmp(char *opcode, char *list)
{
	while (*list != '\0')
	{
		if (*list == ' ')
			list++;
		else if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0' && (*list == ' ' || *list == '\n' || *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * find_new_line - finds newline
 * @list: the string to find \n
 * Return: 1 || 0
 */
int find_new_line(char *list)
{
	char *opcode = "\n";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * push_int - int for push opcode
 * @list: the content of the file
 * @ln: line number
 * Return: the number
 */
int push_int(char *list, int ln)
{
	char *opcode = "push";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || *list == '-')
					{
						comb_find(list, ln);
						return (atoi(list));
					}
					else if (*list == ' ')
						list++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			list++;
	}
	return (0);
}

/**
 * comb_find - finds nonnumbers and number combinations
 * @list: the string
 * @ln: line number
 * Return: 1
 */
int comb_find(char *list, int ln)
{
	int i = 1;

	while (list[i])
	{
		if (list[i] == '\0' || list[i] == '\n')
			break;
		if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
