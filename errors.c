#include "monty.h"

/**
 * handleError - Prints appropriate error messages based on error codes.
 * @errorCode: Error codes:
 * (1) => No file or more than one file provided.
 * (2) => Cannot open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Unable to allocate more memory.
 * (5) => Parameter for "push" instruction is not an int.
 * (6) => Stack is empty for pint.
 * (7) => Stack is empty for pop.
 * (8) => Stack is too short for the operation.
 */
void handleError(int errorCode, ...)
{
	va_list args;
	char *instruction;
	int lineNumber;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			lineNumber = va_arg(args, int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * handleMoreErrors - Handles additional errors.
 * @errorCode: Additional error codes:
 * (6) => Stack is empty for pint.
 * (7) => Stack is empty for pop.
 * (8) => Stack is too short for the operation.
 * (9) => Division by zero.
 */
void handleMoreErrors(int errorCode, ...)
{
	va_list args;
	char *operation;
	int lineNumber;

	va_start(args, errorCode);
	switch (errorCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			lineNumber = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * handleStringErrors - Handles errors related to strings.
 * @errorCode: String error codes:
 * (10) => Number inside a node is outside ASCII bounds.
 * (11) => Stack is empty.
 */
void handleStringErrors(int errorCode, ...)
{
	va_list args;
	int lineNumber;

	va_start(args, errorCode);
	lineNumber = va_arg(args, int);
	switch (errorCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}
