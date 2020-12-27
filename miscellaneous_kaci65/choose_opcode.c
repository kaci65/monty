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
		{NULL, NULL}
	};

	while (op_funcs[index].opcode != NULL)
	{
		if (strcmp(str, op_funcs[index].opcode) == 0)
		{
			(op_funcs[index].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
		index++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);

	return (0);
}
