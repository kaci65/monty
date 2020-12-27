#include "monty.h"

/**
 * div_op - divides second top element of the stack by top element of the stack
 * @top: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void div_op(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	temp->next->n /= (*top)->n;
	(*top)->prev = NULL;
	free(temp);
}
