#include "main.h"
/**
 * execute - executes opcodes
 * @string: contents of file
 * @stack: the list
 * Return: void
 */
void execute(char *string[], stack_t *stack)
{
	int ln, idx, i;

	instruction_t st[] = {
		{"pint", pint}, {"pall", pall}, {"add", add}, {"swap", swap}, {"nop", nop},
		{"push", push_wrapper}, {"pop", pop}, {"nop", nop}, {"null", NULL}};

	for (ln = 1, idx = 0; string[idx + 1]; idx++, ln++)
	{
		if (_strcmp("push", string[idx]))
			push(&stack, ln, push_int(string[idx], ln));
		else if (_strcmp("nop", string[idx]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, string[idx]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(string[idx], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", ln, string[idx]);
				if (!find_new_line(string[idx]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}
