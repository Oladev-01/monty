#include "monty.h"
/**
 * swap - this function swaps the two top value of the stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *hold;

	if (!stack || !ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold = ptr->next->next;
	if (hold)
		hold->prev = ptr;
	*stack = ptr->next;
	(*stack)->prev = NULL;
	(*stack)->next = ptr;
	ptr->next = hold;
	ptr->prev = *stack;
}
