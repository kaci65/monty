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
	char *file = argv[1];

        if (argc != 2)
        {
                fprintf(stderr, "Usage: Monty file\n");
                exit(EXIT_FAILURE);
        }
        file_func(file);
        exit(EXIT_SUCCESS);
}
