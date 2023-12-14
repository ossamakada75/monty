#include "monty.h"

/**
 * doNothing - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void doNothing(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}

/**
 * swapStackNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void swapStackNodes(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErrors(8, lineNumber, "swap");

	tempNode = (*stack)->next;
	(*stack)->next = tempNode->next;
	if (tempNode->next != NULL)
		tempNode->next->prev = *stack;
	tempNode->next = *stack;
	(*stack)->prev = tempNode;
	tempNode->prev = NULL;
	*stack = tempNode;
}

/**
 * addStackNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErrors(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * substractStackNodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void substractStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErrors(8, lineNumber, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divideStackNodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divideStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErrors(8, lineNumber, "div");

	if ((*stack)->n == 0)
		moreErrors(9, lineNumber);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
