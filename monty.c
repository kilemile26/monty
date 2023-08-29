#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 0;
	char opcode[100];
	int value = 0;

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
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return EXIT_SUCCESS;
}
