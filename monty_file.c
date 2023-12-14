#include "monty.h"

/**
 * openMontyFile - Opens a Monty bytecode file.
 * @fileName: The file path.
 * Return: void
 */
void openMontyFile(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
		err(2, fileName);

	readMontyFile(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * readMontyFile - Reads a Monty bytecode file.
 * @fileDescriptor: Pointer to the file descriptor.
 * Return: void
 */
void readMontyFile(FILE *fileDescriptor)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNumber = 1; getline(&buffer, &len, fileDescriptor) != -1; lineNumber++)
	{
		format = parseMontyLine(buffer, lineNumber, format);
	}
	free(buffer);
}

/**
 * parseMontyLine - Parses each line to determine the operation.
 * @buffer: Line from the file.
 * @lineNumber: Line number.
 * @format: Storage format (0 for stack, 1 for queue).
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseMontyLine(char *buffer, int lineNumber, int format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return format;

	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return 0;
	if (strcmp(opcode, "queue") == 0)
		return 1;

	findOperation(opcode, value, lineNumber, format);
	return format;
}

/**
 * findOperation - Finds the appropriate operation for the opcode.
 * @opcode: Opcode.
 * @value: Argument of the opcode.
 * @format: Storage format (0 for stack, 1 for queue).
 * @lineNumber: Line number.
 * Return: void
 */
void findOperation(char *opcode, char *value, int lineNumber, int format)
{
	int i;
	int flag;

	instruction_t operationList[] = {
		{"push", pushToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", noOperation},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotateLeft},
		{"rotr", rotateRight},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; operationList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, operationList[i].opcode) == 0)
		{
			callOperation(operationList[i].operation, opcode, value, lineNumber, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, lineNumber, opcode);
}

/**
 * callOperation - Calls the required operation.
 * @operation: Pointer to the operation that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @lineNumber: Line number for the instruction.
 * @format: Format specifier (0 for stack, 1 for queue).
 */
void callOperation(op_func operation, char *op, char *val, int lineNumber, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, lineNumber);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, lineNumber);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			operation(&node, lineNumber);
		if (format == 1)
			addToQueue(&node, lineNumber);
	}
	else
		operation(&head, lineNumber);
}
