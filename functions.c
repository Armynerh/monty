#include "monty.h"

/**
 * d_exit - exit function with code and free memory
 *
 * @mesg: message
 * @stack: stack
 * @line: line number
 * Return: void
 */
void d_exit(stack_t **stack, const char *mesg, unsigned int line)
{
	fprintf(stderr, "L%u: %s\n", line, mesg);
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * check_num - a function to check if a string contains char
 *
 * @str: string
 * Return: 1 of it does, 0 if it does not
 */
int check_num(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (isalpha(*(str + i)))
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _push - push data at the top of a stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * @args: arguments
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number, char **args)
{
	/*printf("Line %u - push %d on stack\n", line_number, atoi(args[1]));*/
	if (arr_len(args) == 1)
	{
		free(args);
		d_exit(stack, "usage: push integer", line_number);
	}

	if (check_num(args[1]) == -1)
	{
		free(args);
		d_exit(stack, "usage: push integer", line_number);
	}

	add_dnodeint_end(stack, atoi(args[1]));
	free(args);
}

/**
 * _pop - remove the top data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	size_t len;

	/*printf("pop function\n");*/
	len = dlistint_len(*stack);

	if (len == 0)
		d_exit(stack, "can't pop an empty stack", line_number);

	delete_dnodeint_at_index(stack, len - 1);
}

/**
 * _pall - print all data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	/*printf("print all\n");*/
	print_dlistint(*stack);
}

/**
 * _swap - swap the top 2 data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t *node;
	int val;

	/*printf("swap top\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't swap, stack too short", line_number);

	node = get_dnodeint_at_index(*stack, len - 2);
	val = node->n;
	delete_dnodeint_at_index(stack, len - 2);

	add_dnodeint_end(stack, val);
}

/**
 * _add - add the first and second data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	size_t len;
	int sum;

	/*printf("add\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't add, stack too short", line_number);

	node1 = get_dnodeint_at_index(*stack, len - 1);
	node2 = get_dnodeint_at_index(*stack, len - 2);

	sum = node1->n + node2->n;

	delete_dnodeint_at_index(stack, len - 1);
	delete_dnodeint_at_index(stack, len - 2);
	add_dnodeint_end(stack, sum);
}

/**
 * _nop - do nothing
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	;
}

/**
 * _sub - subtract the 2nd data on the stack from the first
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	size_t len;
	int diff;

	/*printf("add\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't sub, stack too short", line_number);

	node1 = get_dnodeint_at_index(*stack, len - 1);
	node2 = get_dnodeint_at_index(*stack, len - 2);

	diff = node1->n - node2->n;

	delete_dnodeint_at_index(stack, len - 1);
	delete_dnodeint_at_index(stack, len - 2);
	add_dnodeint_end(stack, diff);
}

/**
 * _mul - nultiply the last two data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	size_t len;
	int prod;

	/*printf("add\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't mul, stack too short", line_number);

	node1 = get_dnodeint_at_index(*stack, len - 1);
	node2 = get_dnodeint_at_index(*stack, len - 2);
	prod = node1->n * node2->n;

	delete_dnodeint_at_index(stack, len - 1);
	delete_dnodeint_at_index(stack, len - 2);
	add_dnodeint_end(stack, prod);
}

/**
 * _div - divide the 2nd data on the stack by the first
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	size_t len;
	int ddiv;

	/*printf("add\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't div, stack too short", line_number);
	
	node1 = get_dnodeint_at_index(*stack, len - 1);
	node2 = get_dnodeint_at_index(*stack, len - 2);
	
	if (node1->n == 0)
		d_exit(stack, "division by zero", line_number);

	ddiv = node2->n / node1->n;

	delete_dnodeint_at_index(stack, len - 1);
	delete_dnodeint_at_index(stack, len - 2);
	add_dnodeint_end(stack, ddiv);
}

/**
 * _mod - divide the 2nd data on the stack by the first
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;
	size_t len;
	int dmod;

	/*printf("add\n");*/
	len = dlistint_len(*stack);

	if (len < 2)
		d_exit(stack, "can't mod, stack too short", line_number);

	node1 = get_dnodeint_at_index(*stack, len - 1);
	node2 = get_dnodeint_at_index(*stack, len - 2);

	if (node1->n == 0)
		d_exit(stack, "division by zero", line_number);

	dmod = node2->n % node1->n;
	
	delete_dnodeint_at_index(stack, len - 1);
	delete_dnodeint_at_index(stack, len - 2);
	add_dnodeint_end(stack, dmod);
}

/**
 * _pint - print the last data on the stack
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	size_t len;
	stack_t *node;

	/*printf("print top\n");*/
	len = dlistint_len(*stack);

	if (len == 0)
		d_exit(stack, "can't pint, stack empty", line_number);

	node = get_dnodeint_at_index(*stack, len - 1);
	fprintf(stdout, "%u\n", node->n);
}

/**
 * _pchar - print the last data on the stack as char
 *
 * @stack: pointer to the head node of doubly linked list
 * @line_number: data
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
        size_t len;
        stack_t *node;

        /*printf("print top\n");*/
        len = dlistint_len(*stack);

        if (len == 0)
                d_exit(stack, "can't pchar, stack empty", line_number);

        node = get_dnodeint_at_index(*stack, len - 1);

	if (node->n > 255 || node->n < 0)
		d_exit(stack, "can't pchar, value out of range", line_number);

        fprintf(stdout, "%c\n", node->n);
}
