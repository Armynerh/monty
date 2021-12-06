#include "monty.h"

/**
 * free_dlistint - a function that frees a stack_t list.
 *
 * @head: The head node of the list
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *nxt;

	if (head != NULL)
	{
		nxt = head;

		while (nxt != NULL)
		{
			nxt = nxt->next;
			free(head);
			head = nxt;
		}
	}
}
