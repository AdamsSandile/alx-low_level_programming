#include "lists.h"

/**
 * get_safe_list - creates a safe list for printing and checking
 * @oldList: list of nodes
 * @size: size of the current list
 * @node: current node that is being checked in printing
 *
 * Description: creates a new list that can be checked against for
 *              possible looped lists.
 *
 * Return: const list that can be used to check.
 */
listint_t **get_safe_list(listint_t **oldList, int size, listint_t *node)
{
	listint_t **safeList;
	int i;

	safeList = malloc(size * sizeof(listint_t *));
	if (safeList == NULL)
	{
		free(oldList);
		exit(98);
	}

	for (i = 0; i < size - 1; i++)
		safeList[i] = oldList[i];

	safeList[i] = node;
	free(oldList);
	return (safeList);
}

/**
 * free_listint_safe - safely frees a listint_t list
 * @h: pointer to the head node of the list
 *
 * Description: lists may be unsafe and loopy, this function frees lists.
 *
 * Return: number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *next_node;
	listint_t **safeList = NULL;
	int i = 0, j = 0;

	while (*h)
	{
		while (j < i)
		{
			if (*h == safeList[j])
			{
				*h = NULL;
				free(safeList);
				return (i);
			}
			j++;
		}

		i++, j = 0;
		safeList = get_safe_list(safeList, i, *h);
		next_node = (*h)->next;
		free(*h);
		*h = next_node;
	}

	free(safeList);
	return (i);
}

