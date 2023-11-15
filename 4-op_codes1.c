#include "main.h"

/**
 * pop - deletes last element on stack
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothing
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
