#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_elem;

	if (!(*stack || !stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_elem = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(top_elem);
}
