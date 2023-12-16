#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* op_instr*/
void push_element(stack_t **stack, unsigned int line_number);
void print_all_values(stack_t **stack, unsigned int line_number);
void print_top_value(stack_t **stack, unsigned int line_number);
void remove_top_element(stack_t **stack, unsigned int line_number);
void swap_top_elements(stack_t **stack, unsigned int line_number);
void set_queue_format(stack_t **stack, unsigned int line_number);
void set_stack_format(stack_t **stack, unsigned int line_number);
void add_top_elements(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void subtract_top_elements(stack_t **stack, unsigned int line_number);
void divide_top_elements(stack_t **stack, unsigned int line_number);
void modulo_top_elements(stack_t **stack, unsigned int line_number);
void print_char_value(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void divide_top_elements(stack_t **stack, unsigned int line_number);
void multiply_top_elements(stack_t **stack, unsigned int line_number);
void modulo_top_elements(stack_t **stack, unsigned int line_number);
void print_char_value(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);

/*get fun*/
void (*get_opcode_function(char *opcode))(stack_t **stack, unsigned int line_number);

/*import function*/
int _custom_strcmp(char *str1, char *str2);
int _char_search(char *str, char c);
void *custom_calloc(unsigned int nmemb, unsigned int size);
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_custom_strtok(char *str, char *delimiters);

/* doubly linked list functions */
stack_t *add_node_at_end(stack_t **head, const int n);
stack_t *add_node_at_start(stack_t **head, const int n);
void free_doubly_linked_list(stack_t *head);

/* main */
void free_vglo(void);

#endif
