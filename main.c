#include "monty.h"
stack_t *head = NULL;
/**
 * main - Program entry point.
 * @argc: Number of command line arguments.
 * @argv: double pointer array to arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		error_check(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}
