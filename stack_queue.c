#include "monty.h"

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack; /*Unused parameter*/
	(void)line_number; /*Unused parameter*/
	/*The default behavior is already LIFO (stack), so nothing needs to be done*/
}

void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *second_last;
	(void)line_number; /*Unused parameter*/

	if (*stack == NULL || (*stack)->next == NULL)
		return; /*Nothing to change*/

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
