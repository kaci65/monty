#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

#define DELIM " \n\r\t\a"

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

/*Stack/queue operations.*/
void push(stack_t **stack, unsigned int element);
void print_all(stack_t **top, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

void free_nodes(void);
stack_t *create_node(int n);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void nop(stack_t **, unsigned int);


/*endoftest*/
stack_t *create_node(int n);

typedef void (*op_func)(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);

/*File manipulation*/
void open_file(char *);
void read_file(FILE *fd);
int monty_func_s(char *lineptr, int line_no, int specifier);
void determine_func(char *opcode, char *value, int l_no, int specifier);

/*Error handling*/
void error_check(int error_code, ...);

extern stack_t *head;
#endif /* #ifndef MONTY_H */
