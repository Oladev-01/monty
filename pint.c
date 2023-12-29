#include "monty.h"
/**
 * pint - this function prints the value at the top of stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: the line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	printf("%d\n", ptr->n);
}

/**
 * confirm_op_arg - this function checks
 *  for the validity of the arg parsed to the push
 * @token: the argument
 * @pts: file pointer
 * @line_number: line number
 * Return: void
 */
void confirm_op_arg(char *token, FILE *pts, unsigned int line_number)
{

	if (token)
	{
		check_digit_1(token, pts, line_number);
		data.num = atoi(token);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - this function deletes the top of the stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: the line number
 * Return: void
 */
g_data data;
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(ptr);
}

