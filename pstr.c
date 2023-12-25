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
