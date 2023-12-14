#include "monty.h"

/**
 * addNodeToStack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addNodeToStack(stack_t **newNode, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *temporaryNode;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	temporaryNode = head;
	head = *newNode;
	head->next = temporaryNode;
	temporaryNode->prev = head;
}

/**
 * printStack - Prints the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temporaryNode;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temporaryNode = *stack;
	while (temporaryNode != NULL)
	{
		printf("%d\n", temporaryNode->n);
		temporaryNode = temporaryNode->next;
	}
}

/**
 * popFromStack - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void popFromStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temporaryNode;

	if (stack == NULL || *stack == NULL)
		moreErrors(7, lineNumber);

	temporaryNode = *stack;
	*stack = temporaryNode->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temporaryNode);
}

/**
 * printTopNode - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printTopNode(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		moreErrors(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
