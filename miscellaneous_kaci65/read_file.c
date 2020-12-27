#include "monty.h"

/**
 * file_func - opens and read  a file
 * @filename: file to be opened and read
 * Return: Nothing
 */
void file_func(char *filename)
{
	FILE *file_pointer;
	size_t buf_size = 0;
	char *buf = NULL;
	char *op_code;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	ssize_t line_count;

	file_pointer = fopen(filename, "r");
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line_count = getline(&buf, &buf_size, file_pointer);
	while (line_count != EOF)
	{
		op_code = strtok(buf, DELIM);
		if (op_code == NULL)
		{
			continue;
		}
		else
		{
			get_opfunc(op_code, &stack, line_number);
		}
	}
	fclose(file_pointer);
	free(buf);
	free_stack(stack);
}
