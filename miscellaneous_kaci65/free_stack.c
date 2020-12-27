#include "monty.h"

/**
 * free_stack - frees data on stack
 * @stack: Pointer to stack
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *nodes;

	while (stack != NULL)
	{
		nodes = stack;
		stack = stack->next;
		free(nodes);
	}
}
