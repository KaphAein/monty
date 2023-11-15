#include "main.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * @head: List head
 * @n: node data
 * Return: the address of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * add_dnodeint_end - adds a new node at the end
 * @head: List head
 * @n: node data
 * Return: the address of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	current = *head;

	while (current && current->next)
		current = current->next;
	if (current)
	{
		new_node->prev = current;
		current->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: List head
 * @index: node index
 * Return: return 1 for success -1 for fail
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int i;

	if (head == NULL)
		return (-1);

	current = *head;

	for (i = 0; i < index && current; i++)
		current = current->next;

	if (!current)
		return (-1);
	if (current->prev)
		current->prev->next = current->next;
	else
		*head = current->next;

	if (current->next)
		current->next->prev = current->prev;
	free(current);
	return (1);
}

/**
 * free_stack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

/**
 * free_list - frees getline list
 * @a: pointer to array of strings
 * Return: Nothing
 */
void free_list(char *a[])
{
	int i = 0;

	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
}
