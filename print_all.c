#include <stdio.h>
#include "monty.h"

/**
 *print_all - prints all values on the stack, starting from top of stack
 *@stack: pointer to the top of stack
 *@line_number: line to be evaluated
 *Return: nothing
 */
void print_all(stack_t **top, unsigned int line_number)
{
	stack_t *node = *top;

	(void)(line_number);

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node->next = node;
	}
}
