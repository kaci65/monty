#include "monty.h"

/**
 * print_top - prints value at the top of the stack
 * @stack: pointer to the top of stack
 * @line_number: line to be evaluated
 * Return: nothing
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if  (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
