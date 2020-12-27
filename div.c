#include "monty.h"

/**
 * div_op - divides second top element of the stack by top element of the stack
 * @top: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void div_op(stack_t **top, unsigned int line_number)
{
	stack_t *temp = NULL;
	int stack_nodes = 0;

	if (stack_nodes < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	temp = (*top)->next;
	temp->prev = NULL;
	(*top) = temp;
	free(temp);
}
