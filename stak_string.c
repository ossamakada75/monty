#include "monty.h"

/**
 * printAsciiCharacter - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printAsciiCharacter(stack_t **stack, unsigned int lineNumber)
{
	int asciiValue;

	if (stack == NULL || *stack == NULL)
		stringErrors(11, lineNumber);

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
		stringErrors(10, lineNumber);
	printf("%c\n", asciiValue);
}

/**
 * printString - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printString(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	int asciiValue;
	stack_t *temporaryNode;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temporaryNode = *stack;
	while (temporaryNode != NULL)
	{
		asciiValue = temporaryNode->n;
		if (asciiValue <= 0 || asciiValue > 127)
			break;
		printf("%c", asciiValue);
		temporaryNode = temporaryNode->next;
	}
	printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *temporaryNode;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temporaryNode = *stack;
	while (temporaryNode->next != NULL)
		temporaryNode = temporaryNode->next;

	temporaryNode->next = *stack;
	(*stack)->prev = temporaryNode;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *temporaryNode;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temporaryNode = *stack;

	while (temporaryNode->next != NULL)
		temporaryNode = temporaryNode->next;

	temporaryNode->next = *stack;
	temporaryNode->prev->next = NULL;
	temporaryNode->prev = NULL;
	(*stack)->prev = temporaryNode;
	(*stack) = temporaryNode;
}
