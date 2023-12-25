#include "monty.h"
/**
 * mod - this function computes the modulo of the-
 * second element by the top and store in the second.
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	 stack_t *ptr = *stack, *hold;
	int mod;

	if (!stack || !ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold = ptr->next;
	mod = ptr->n;
	if (mod == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	hold->n = hold->n % mod;
	pop(stack, line_number);
}

/**
 * pchar - this function prints the character estimate of the top data
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int ret;

	if (!stack || !ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ret = ptr->n;
	if (!(ret >= 0 && ret <= 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ret);
}
