#include "monty.h"
/**
 * sub_opcode - subtracts the top element of the stack from 2nd top element.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub_opcode(stack_t **stack, unsigned int line_num)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
