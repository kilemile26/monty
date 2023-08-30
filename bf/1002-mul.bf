#include "monty.h"

void mul_digits(stack_t **stack, unsigned int line_number)
{
	int digit1;
	int digit2;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	digit1 = (*stack)->n;
	digit2 = (*stack)->next->n;
	result = digit1 * digit2;

	pop(stack, line_number);
	(*stack)->n = result;
}
