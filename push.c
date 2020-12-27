#include "monty.h"

/**
 *push - pushes an element to the stack
 *@top: pointer to the top of stack
 *@element: element to be pushed
 *Return: nothing
 */
void push(stack_t **top, unsigned int element)
{
	stack_t *new_top;

	new_top = malloc(sizeof(stack_t));

	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_top->prev = NULL;
	new_top->n = element;

	if (*top)
	{
		new_top->next = *top;
		(*top)->prev = new_top;

		if (*top == NULL)
		{
			new_top->next = NULL;
			*top = new_top;
		}
	}
	*top = new_top;
}
