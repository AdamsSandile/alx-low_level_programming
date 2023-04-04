#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at the beginning of a singly linked list.
 * @head: Pointer to the head of the list.
 * @n: Integer value to insert into the new node.
 *
 * Return: The address of the new node, or NULL if allocation fails.
 **/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *tp;

	tp = malloc(sizeof(listint_t));
	if (tp == NULL)
		return (NULL);

	tp->n = n;
	tp->next = *head;
	*head = tp;

	return (tp);
}
