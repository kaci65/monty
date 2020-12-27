#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

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

/*stack operations*/
void push(stack_t **stack, unsigned int element);
void print_all(stack_t **top, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* opcode operations */
int get_opfunc(char *str, stack_t **stack, unsigned int line_number);
void file_func(char *filename);

/* free stack */
void free_stack(stack_t *stack);

#endif /* #ifndef MONTY_H */
