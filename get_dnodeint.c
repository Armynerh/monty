#include "monty.h"

/**
 * get_dnodeint_at_index - a function that returns the nth node of
 * a stack_t linked list.
 *
 * @head: The head node of the list
 * @index: the index to return
 * Return: Node data at index, if the node does not exist, return NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	stack_t *h;
	unsigned int count = 0;

	h = head;

	while (h != NULL)
	{
		if (index == count)
			return (h);
		h = h->next;
		count++;
	}
	return (NULL);
}
