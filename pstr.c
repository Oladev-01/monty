#include "monty.h"
/**
 * pstr - this prints the stack as a string
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int ret;

	(void)line_number;
	if (!ptr)
	{
		printf("\n");
		return;
	}
	while (ptr)
	{
		ret = ptr->n;
		if (ret > 0 && ret <= 127)
		{
			printf("%c", ret);
		}
		else
			break;
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * rotl - this function rotates stack
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack, *hold;

	(void)line_number;
	if (!stack || !ptr || !ptr->next)
		return;
	*stack = ptr->next;
	if (stack)
	{
		(*stack)->prev = NULL;
		hold = *stack;
		while (hold->next)
			hold = hold->next;
		hold->next = ptr;
		ptr->prev = hold;
		ptr->next = NULL;
	}
}
