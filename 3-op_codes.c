#include "main.h"

/**
 * push - new element on stack
 * @stack: List head
 * @line_num: line number
 * @n: node data
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_num, int n)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, n);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * push_wrapper - new element on stack
 * @stack: List head
 * @line_number: line number
 * Return: nothing
 */
void push_wrapper(stack_t **stack, unsigned int line_number)
{
	push(stack, line_number, 0);
}

/**
 * pall - prints all stack
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - prints element top of stack
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	if (h)
	{
		printf("%d\n", h->n);
	}
}

/**
 * swap - swaps between first two element on stack
 * @stack: List head
 * @line_num: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
stack_t *h = *stack, *tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		tmp = h->next;
		if (tmp->next)
			tmp->next->prev = h;
		h->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = h;
		h->prev = tmp;
		*stack = tmp;
	}
}
