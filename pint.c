#include "monty.h"
/**
 * pint - this function prints the value at the top of stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: the line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	free_list(stack);
}
