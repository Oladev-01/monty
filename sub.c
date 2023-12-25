#include "monty.h"
/**
 * sub - this function subtracts the top element from the second element
 * of the stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *hold;
	int sum = 0;

	if (!stack || !ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold = ptr->next;
	sum += hold->n;
	sum -= ptr->n;
	hold->n = sum;
	pop(stack, line_number);
}
