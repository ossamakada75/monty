#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int)

/*file operations*/
void openMontyFile(char *fileName);
void readMontyFile(FILE *fileDescriptor);
int parseMontyLine(char *buffer, int lineNumber, int format);
void findOperation(char *opcode, char *value, int lineNumber, int format);
void callOperation(op_func operation, char *op, char *val, int lineNumber, int format);

/*errors*/
void handleError(int errorCode, ...);
void handleMoreErrors(int errorCode, ...);
void handleStringErrors(int errorCode, ...);

/*Stack*/
void addNodeToStack(stack_t **newNode, __attribute__((unused))unsigned int lineNumber);
void printStack(stack_t **stack, unsigned int lineNumber);
void popFromStack(stack_t **stack, unsigned int lineNumber);
void printTopNode(stack_t **stack, unsigned int lineNumber);

void doNothing(stack_t **stack, unsigned int lineNumber);
void swapStackNodes(stack_t **stack, unsigned int lineNumber);
void addStackNodes(stack_t **stack, unsigned int lineNumber);
void substractStackNodes(stack_t **stack, unsigned int lineNumber);
void divideStackNodes(stack_t **stack, unsigned int lineNumber);

void multiplyStackNodes(stack_t **stack, unsigned int lineNumber);
void moduloStackNodes(stack_t **stack, unsigned int lineNumber);

void printAsciiCharacter(stack_t **stack, unsigned int lineNumber);
void printString(stack_t **stack, __attribute__((unused))unsigned int lineNumber);
void rotateLeft(stack_t **stack, __attribute__((unused))unsigned int lineNumber);
void rotateRight(stack_t **stack, __attribute__((unused))unsigned int lineNumber);

/*Math operations*/
int main(int argc, char *argv[]);
stack_t *createNode(int n);
void freeStackNodes(void);
void enqueueNode(stack_t **newNode, __attribute__((unused))unsigned int ln);
#endif
