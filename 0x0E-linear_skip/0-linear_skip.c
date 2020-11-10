#include "search.h"

/**
 * linear_skip - Linear skip search function
 * @list: List to search
 * @value: Value to find
 * Return: Null or a pointer to the node w/ value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = malloc(sizeof(skiplist_t));
	skiplist_t *last_node = malloc(sizeof(skiplist_t));
	skiplist_t *tail = malloc(sizeof(skiplist_t));

	char *val_checked = "Value checked at index";
	char *val_found = "Value found between indexes";

	if (list == NULL)
		return (NULL);

	if (value < list->n)
		return (NULL);

	current = list->express;
	last_node = list;
	tail = list;

	while (tail->next)
	{
		tail = tail->next;
	}

	while (current)
	{
		printf("%s [%lu] = [%d]\n", val_checked, current->index, current->n);
		if (current->n >= value)
		{
			printf("%s [%lu] and [%lu]\n", val_found, last_node->index, current->index);
			return (traverse(last_node, value));
		}
		if (current->express == NULL)
		{
			printf("%s [%lu] and [%lu]\n", val_found, current->index, tail->index);
			return (traverse(current, value));
		}
		last_node = current;
		current = current->express;
	}
	return (NULL);
}

/**
 * traverse - Traverses a linked list
 * @last_node: The node to start traversal at
 * @value: The value to search for
 * Return: Null or the found node
 */
skiplist_t *traverse(skiplist_t *last_node, int value)
{
		char *val_checked = "Value checked at index";

		while (last_node->n <= value)
		{
			printf("%s [%lu] = [%d]\n", val_checked, last_node->index, last_node->n);
			if (last_node->n == value)
				return (last_node);
			last_node = last_node->next;
			if (last_node == NULL)
				break;
		}
		return (NULL);
}
