#include "monty.h"
stack_t *stackHead = NULL;

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeStackNodes();
	return (0);
}

/**
 * createNode - Creates a new node.
 * @n: Number to be stored in the node.
 * Return: A pointer to the new node on success, otherwise NULL.
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeStackNodes - Frees nodes in the stack.
 */
void freeStackNodes(void)
{
	stack_t *tmp;

	if (stackHead == NULL)
		return;

	while (stackHead != NULL)
	{
		tmp = stackHead;
		stackHead = stackHead->next;
		free(tmp);
	}
}

/**
 * enqueueNode - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void enqueueNode(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (stackHead == NULL)
	{
		stackHead = *newNode;
		return;
	}
	tmp = stackHead;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}
