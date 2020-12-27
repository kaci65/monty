#include <stdio.h>
#include "monty.h"

/**
 *print_all - prints all values on the stack, starting from top of stack
 *@top: pointer to the top of stack
 *@line_number: line to be evaluated
 *Return: nothing
 */
void print_all(stack_t **top, unsigned int line_number)
{
	stack_t *node = *top;

	(void)(line_number);
	if (top == NULL)
		exit(EXIT_FAILURE);

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
