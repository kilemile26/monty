#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 0;
	char opcode[100];
	int value = 0;
	char *trimmed_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		/*Skip leading spaces*/
		trimmed_line = line;
		while (*trimmed_line == ' ' || *trimmed_line == '\t')
		{
			trimmed_line++;
		}

		/*Skip comment lines*/
		if (*trimmed_line == '#' || *trimmed_line == '\n')
		{
			continue; /*Skip this line, treat it as a comment*/
		}

		/* Parse the opcode and value (if any)*/
		sscanf(line, "%s", opcode);

		if (sscanf(line, "%s %d", opcode, &value) == 1)
		{
			value = 0; /* No value provided*/
		}

		/* Check opcode and perform corresponding action*/
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub(&stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			div_op(&stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul(&stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			mod(&stack, line_number);
		}
		else if (strcmp(opcode, "pchar") == 0)
		{
			pchar(&stack, line_number);
		}
		else if (strcmp(opcode, "pstr") == 0)
		{
			pstr(&stack, line_number);
		}
		else if (strcmp(opcode, "rotl") == 0)
		{
			rotl(&stack, line_number);
		}
		else if (strcmp(opcode, "rotr") == 0)
		{
			rotr(&stack, line_number);
		}
		else if (strcmp(opcode, "stack") == 0)
		{
			stack(&stack, line_number);
		}
		else if (strcmp(opcode, "queue") == 0)
		{
			queue(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return EXIT_SUCCESS;
}
