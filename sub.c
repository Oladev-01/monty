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
	int sub = 0;

	if (!stack || !ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold = ptr->next;
	sub += hold->n;
	sub -= ptr->n;
	hold->n = sub;
	pop(stack, line_number);
}

/**
 * div - this function divides the second element-
 * of the stack by the first element
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
 */
void div_stack(stack_t **stack, unsigned int line_number)
{

	stack_t *ptr = *stack, *hold;
	int div;

	if (!stack || !ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold = ptr->next;
	div = ptr->n;
	if (div == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold->n = hold->n / div;
	pop(stack, line_number);
}
