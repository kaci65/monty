#include "monty.h"

/**
 * get_opfunc - get opcode function and execute it
 * @str: pointer to string containing opcodes
 * @stack: pointer to stack
 * @line_number: line to be evaluated
 * Return: 0 if successful
 */
int get_opfunc(char *str, stack_t **stack, unsigned int line_number)
{
	int index = 0;

	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop},
		{"swap", swap_nodes},
		{"add", add_opcode},
		{"nop", nop},
		{"sub", sub_opcode},
		{NULL, NULL}
	};

	while (op_funcs[index].opcode != NULL)
	{
		if (strcmp(str, op_funcs[index].opcode) == 0)
		{
			(op_funcs[index].f);
		}
		index++;
	}
	if (op_funcs[index].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
		exit(EXIT_FAILURE);
	}
	return (0);
}
