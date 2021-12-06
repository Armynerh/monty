#include "monty.h"

/**
 * print_dlistint - a function that prints all the elements of
 * a stack_t
 *
 * @h: pointer to the head node of the list
 * Return: The number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	const stack_t *head;
	int count = 0;

	head = h;

	while (head->next != NULL)
	{
		head = head->next;
		count++;
	}

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->prev;
		count++;
	}
	return (count);
}
