#include "monty.h"
/**
 * queue - this function sets the head node to a queue mode
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mode = QUEUE;
}

/**
 * stacks - this function sets the list to stack mode
 * @stack: the pointer to the pointer to the head node
 * @line_number: line number
 * Return: void
 */
void stacks(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mode = STACK;
}
