#include "lists.h"

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num = 0;
	const listint_t *visited[1024] = {NULL}; /* hash table to store visited nodes */
	unsigned long int index;

	while (head)
	{
		/* check if the node has already been visited */
		index = (unsigned long int)head % 1024;
		if (visited[index] == head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}

		/* add the node to the hash table */
		visited[index] = head;

		/* print the node */
		num++;
		printf("[%p] %d\n", (void *)head, head->n);

		/* move to the next node */
		head = head->next;
	}

	return (num);
}

