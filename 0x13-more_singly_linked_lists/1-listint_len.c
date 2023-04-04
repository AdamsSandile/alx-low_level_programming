#include "lists.h"

/**
 * listint_len - Calculates the number of elements in a singly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 **/
size_t listint_len(const listint_t *h)
{
	const listint_t *tp;
	unsigned int cnr = 0;

	for (tp = h; tp != NULL; tp = tp->next)
	{
		cnr++;
	}

	return (cnr);
}
