#include "monty.h"

/**
 * create_node - Creates and populates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_check(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
