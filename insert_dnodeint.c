#include "monty.h"

/**
 * insert_dnodeint_at_index - a function that inserts a new node at a
 * given position
 *
 * @h: pointer to the head node
 * @idx: Index to add
 * @n: data to add
 * Return: Pointer of the new node
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *head;
	stack_t *new;
	unsigned int node_count = 0;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	head = *h;

	while (head != NULL)
	{
		if (node_count == idx - 1)
		{
			new->n = n;
			new->next = head->next;
			new->prev = head;
			head->next = new;

			return (new);
		}

		head = head->next;
		node_count++;
	}
	return (NULL);
}
