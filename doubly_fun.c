#include "monty.h"

/**
 * add_node_at_end - Adds a node at the end of the doubly linked list.
 *
 * @head: Pointer to the first position of the linked list.
 * @n: Data to store in the new node.
 * Return: A pointer to the doubly linked list.
 */
stack_t *add_node_at_end(stack_t **head, const int n)
{
	stack_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	current = *head;
	while (current->next)
		current = current->next;

	new_node->next = current->next;
	new_node->prev = current;
	current->next = new_node;

	return (current->next);
}

/**
 * add_node_at_start - Adds a node at the beginning of the doubly linked list.
 *
 * @head: Pointer to the first position of the linked list.
 * @n: Data to store in the new node.
 * Return: A pointer to the doubly linked list.
 */
stack_t *add_node_at_start(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	(*head)->prev = new_node;
	new_node->next = (*head);
	new_node->prev = NULL;
	*head = new_node;

	return (*head);
}

/**
 * free_doubly_linked_list - Frees the doubly linked list.
 *
 * @head: Head of the list.
 * Return: No return.
 */
void free_doubly_linked_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}

