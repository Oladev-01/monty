#include "monty.h"
/**
 * push - this function pushes a new data into the stack
 * @stack: this is the pointer to the pointer to the head node
 * @line_number: this specifies the index of the node
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *ptr = *stack;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (!new_node || !stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = data.num;
	if (data.mode == STACK)
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	if (data.mode == QUEUE)
	{
		if (!(*stack))
			*stack = new_node;

		else
		{
			ptr = *stack;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->prev = ptr;
			new_node->next = NULL;
		}
	}
}

/**
 * pall - this function prints all elements of a stack
 * @stack: this is the pointer to the pointer to the head node
 * @line_number: this is the number of node
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * free_list - this function frees the stack
 * @stack: this the head pointer
 * Return: void
*/
void free_list(stack_t **stack)
{
	stack_t *ptr;

	if (!stack)
		return;
	ptr = *stack;
	while (ptr)
	{
		*stack = ptr->next;
		free(ptr);
		ptr = *stack;
	}
}
