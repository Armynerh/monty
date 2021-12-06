#include "monty.h"

/**
 * dlistint_len - a function that returns the number of elements
 * in a linked stack_t list.
 *
 * @h: pointer to the head node of the list
 * Return: The number of nodes
 */
size_t dlistint_len(const stack_t *h)
{
	const stack_t *head;
	int count = 0;

	head = h;

	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}
