#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop ab empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_node = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top_node);
}
