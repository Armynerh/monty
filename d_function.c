#include "monty.h"

/**
 * arr_len - get length of null ending array
 *
 * @arr: array of arrays
 * Return: length
 */
int arr_len(char **arr)
{
	int len = 0;

	while (*(arr + len) != NULL)
		len++;

	return (len);
}

/**
 * d_function - The function that assigns opcodes to its various functions
 *
 * @argv: arguments
 * @stack: pointer to head of list
 * @line: Line number
 * Return: Int
 */
int d_function(char **argv, stack_t **stack, unsigned int line)
{
	int i, n = 11;

	instruction_t instruct[] = {
		{"pop", _pop},
		{"pint", _pint},
		{"pall", _pall},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
	};

	/*printf("Line number = %u\n", line);*/
	for (i = 0; i < n; i++)
	{
		if (strcmp(argv[0], instruct[i].opcode) == 0)
		{
			/*printf("val = %u\n",val);*/
			free(argv);
			instruct[i].f(stack, line);
			return (0);
		}

		if (strcmp(argv[0], "push") == 0)
		{
			_push(stack, line, argv);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, argv[0]);
	return (0);
}
