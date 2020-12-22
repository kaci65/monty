#include "monty.h"

/**
 *push - pushes an element to the stack
 *@top: pointer to the top of stack
 *@element: element to be pushed
 *Return: nothing
 */
void push(stack_t **top, unsigned int element)
{
	stack_t *new_top, *tmp;

	tmp = *top;
	new_top = malloc(sizeof(stack_t));

	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_top->n = element;
	new_top->prev = NULL;
	new_top->next = NULL;

	if (*top)
	{
		new_top->next = *top;
		new_top->prev = NULL;
		tmp->next = new_top;
		new_top->prev = tmp;
	}
	*top = new_top;
}
