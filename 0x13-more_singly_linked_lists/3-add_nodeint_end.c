#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds a new node at the end of a singly linked list.
 * @head: Pointer to the head of the list.
 * @n: Integer value to insert into the new node.
 *
 * Return: The address of the new node, or NULL if allocation fails.
 **/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp, *temp2;

	temp = malloc(sizeof(listint_t));
	if (temp == NULL)
		return (NULL);


	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return (temp);
	}

	temp2 = *head;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;

	return (temp);
}
