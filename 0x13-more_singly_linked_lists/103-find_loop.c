#include "lists.h"

/**
 * find_listint_loop - finds loop in a linked list
 * @head: head node of the linked list
 *
 * Description: finds a looped list using two pointers.
 *              The first pointer moves one node at a time
 *              while the second pointer moves two nodes at a time.
 *              If there is a loop, the two pointers will eventually meet.
 *              After they meet, the first pointer is reset to the
 *              beginning of the list, and both pointers move one node
 *              at a time until they meet again at the start of the loop.
 *
 * Return: address of node where loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slowPtr = head, *fastPtr = head;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slowPtr = slowPtr->next;
	fastPtr = fastPtr->next->next;

	while (fastPtr && fastPtr->next)
	{
		if (slowPtr == fastPtr)
			break;

		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}

	if (slowPtr != fastPtr)
		return (NULL);

	slowPtr = head;

	while (slowPtr != fastPtr)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}

	return (slowPtr);
}

