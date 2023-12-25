#include "monty.h"
/**
 * push - this function pushes a new data into the stack
 * @stack: this is the pointer to the pointer to the head node
 * @line_number: this specifies the index of the node
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (!new_node || !stack)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
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

	if (!stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	free_list(stack);
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
