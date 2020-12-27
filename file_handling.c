#include "monty.h"

/**
 * open_file - Open a file.
 * @file_name: Pointer to a file.
 */

void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		error_check(2, file_name);
	/*Checks if we have file read permission.(R_OK)*/
	/*default unistd.h implementation"*/
	/*int access (const char *filename, int how)*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
		error_check(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_check(2, file_name);

	/*read the contents of the file.*/
	read_file(fd);
	/*close the filestream.*/
	fclose(fd);
}
/**
 * read_file - Reads file content, line by line..
 * @fd: Pointer to a file descriptor of an open file
 */
void read_file(FILE *fd)
{
	int line_no;
	int specifier = 0;
	char *lineptr = NULL;
	size_t n = 0;

	/*Check if the fd pointer points to an empty file*/
	if (fd == NULL)
		error_check(2, "file_name");

	/*Getting each line in the file from the stream fd*/
	/*and storing the address of the line in lineptr*/
	for (line_no = 1; getline(&lineptr, &n, fd) != EOF; line_no++)
	{
		specifier = monty_func_s(lineptr, line_no, specifier);
	}
	free(lineptr);
}


/**
 * monty_func_s -splits each line into tokens,determines func to call
 * @lineptr: Pointer to a line in a file.
 * @line_no: Line number of the operation code(op_code)
 *@specifier: determines operation to perform, 1 for queue, 0 for stack
 * Return: Returns 0 if  stack. 1 if queue.
 */
int monty_func_s(char *lineptr, int line_no, int specifier)
{
	const char *delim = "\n ";
	char *opcode;
	char *value;

	if (lineptr == NULL)
		error_check(4);
	/* Get the fist token*/
	opcode = strtok(lineptr, delim);

	/*check blank lines blank lines*/
	if (opcode == NULL)
		return (specifier);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	determine_func(opcode, value, line_no, specifier);
	return (specifier);
}

/**
 * determine_func - determine the right func to run the opcode instructions.
 * @opcode: Pointer to the opcode.
 * @value: The possible value for the operation.
 * @l_no: opcode line number
 * @specifier: determines operations to perform, 1 for queue, 0 for stack.
 */
void determine_func(char *opcode, char *value, int l_no, int specifier)
{
	int i;
	int flag;

	instruction_t f_list[] = {
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop},
		{"div", div_op},
		{"mul", mul},
		{"push", add_to_stack},
		{"swap", swap_nodes},
		{"add", add_opcode},
		{"nop", nop},
		{"sub", sub_opcode},
		{NULL, NULL}
	};
	/*comments implementation*/
	if (opcode[0] == '#')
	{
		return;
	}
	/*Iterates through list to find the right function*/
	for (flag = 1, i = 0; f_list[i].opcode != NULL; i++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, f_list[i].opcode) == 0)
		{
			call_fun(f_list[i].f, opcode, value, l_no, specifier);
			flag = 0;
		}
	}
	/*Instruction is found but is unknown.*/
	if (flag == 1)
		error_check(3, l_no, opcode);
}

/**
 * call_fun - Calls the right function to execute the opcode
 * @f: Pointer to the function to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @line_no: line numeber for the instruction.
 * @specifier: determines the operation to perform, 0 for stack, 1 for queue.
 */

void call_fun(op_func f, char *op, char *val, int line_no, int specifier)
{
	stack_t *node;
	/*variable for testing if a num is +ve or -ve.*/
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		/*Checks if the number is negative and moves the val ptr*/
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		/*val is not a digit is the return value*/
		if (val == NULL)
			error_check(5, line_no);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_check(5, line_no);
		}
		node = create_node(atoi(val) * flag);
		if (specifier == 0)
			f(&node, line_no);
		if (specifier == 1)
			add_to_queue(&node, line_no);
	}
	else
		f(&head, line_no);
}
