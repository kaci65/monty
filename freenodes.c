#include "monty.h"
/**
 * free_nodes - Free a node in the stack.
 */
void free_nodes(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
