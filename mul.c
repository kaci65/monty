#include "monty.h"

/**
 * mul - multiplies second top element of the stack by top element of the stack
 * @top: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void mul(stack_t **top, unsigned int line_number)
{
	int top_node, res;

	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_node = (*top)->n;
	res = top_node * ((*top)->next->n);
	pop(top, line_number);
	(*top)->n = res;
}
