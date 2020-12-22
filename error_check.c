#include "monty.h"

/**
 * error_check - Prints error messsage as per the error code.
 * @error_code:Code specifying a particular error.
 */
void error_check(int error_code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, error_code);
	switch (error_code)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
		       va_arg(args, char *));
		break;
	case 3:
		line_num = va_arg(args, int);
		op = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
		break;
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
		       va_arg(args, int));
		break;
	case 8:
		line_num = va_arg(args, unsigned int);
		op = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}
