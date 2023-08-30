#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *second_last;
	(void)line_number; /*Unused parameter*/

	if (*stack == NULL || (*stack)->next == NULL)
		return; /*Nothing to rotate*/

	last = *stack;
	second_last = NULL;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
