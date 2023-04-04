#include "lists.h"
#include <stdio.h>
/**
 * print_listint - Prints the elements of a singly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 **/
size_t print_listint(const listint_t *h)
{
	const listint_t *tp;

	unsigned int cntr = 0;

	for (tp = h; tp != NULL; tp = tp->next)
	{
		printf("%d\n", tp->n);
		cntr++;
	}

	return (cntr);
}
