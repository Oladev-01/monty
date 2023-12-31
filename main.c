#include "monty.h"
/**
 * main - this is the entry function
 * @ac: this is the arg count
 * @av: args
 * Return: 0 for success
 */
int main(int ac, char **av)
{
	FILE *pts;
	char *file, line[1000], *token, *opcodes;
	unsigned int line_number = 1;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = av[1];
	pts = fopen(file, "r");
	if (!pts)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data.mode = NTN;
	while (fgets(line, sizeof(line), pts))
	{
		token = strtok(line, " \n");
		opcodes = token;
		token = strtok(NULL, " \n");
		if (opcodes && strcmp(opcodes, "push") == 0)
			confirm_op_arg(token, pts, line_number);
		if (opcodes)
			chk_op(&head, opcodes, line_number, pts);
		line_number++;
	}
	free_list(&head);
	fclose(pts);
	return (0);
}

/**
 * check_digit - this function checks if the argument
 *  parsed to the opcode is a valid integer
 * @token: this is the string to check for
 * @line_number: this is the line number
 * @pts: the file pointer
 * Return: void
 */
void check_digit(char *token, FILE *pts, unsigned int line_number)
{
	if (!token || (!isdigit(token[0]) && (token[0] != '-' || !isdigit(token[1]))))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(pts);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_digit_1 - this function checks if the argument
 * parsed to the opcode is a valid integer
 * @line_number: this is the line number
 * @pts: the file pointer
 * @token: the string
 * Return: void
 */
void check_digit_1(char *token, FILE *pts, unsigned int line_number)
{
	int j = 0;

	while (token[j])
	{
		check_digit(token + j, pts, line_number);
		j++;
	}
}

/**
 * chk_op - this function checks for the validity of the opcode
 * @head: pointer to the pointer to the head node
 * @opcodes: this is the opcode extracted from the file
 * @line_number: this is the line number of the file
 * @pts: the file pointer
 * Return: void
 */
void chk_op(stack_t **head, char *opcodes, unsigned int line_number, FILE *pts)
{
	int i, check;
	instruction_t ptr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_stack},
		{"mul", mul_ty},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stacks},
		{NULL, NULL}
		};

	if (opcodes[0] == '#')
		return;

	for (i = 0; ptr[i].opcode != NULL; i++)
	{
		check = strcmp(ptr[i].opcode, opcodes);
		if (check == 0)
		{
			ptr[i].f(head, line_number);
			break;
		}
	}
	if (check != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcodes);
		fclose(pts);
		exit(EXIT_FAILURE);
	}
}
