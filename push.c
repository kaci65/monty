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

	new_top = create_node(element);

	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*top)
	{
		new_top->next = *top;
		new_top->prev = NULL;
		if (!(*top))
		{
			(*top)->prev = new_top;
		}
	}
	*top = new_top;
}
