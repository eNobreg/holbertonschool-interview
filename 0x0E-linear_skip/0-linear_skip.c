#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = malloc(sizeof(skiplist_t));
	skiplist_t *last_node = malloc(sizeof(skiplist_t));
	skiplist_t *tail = malloc(sizeof(skiplist_t));

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
		printf("Value checked at index[%lu] = [%d]\n", current->index, current->n);
		if (current->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", last_node->index, current->index);
			return (traverse(last_node, value));
		}
		if (current->express == NULL)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", current->index, tail->index);
			return(traverse(current, value));
		}
		last_node = current;
		current = current->express;
	}
	return (NULL);
}

skiplist_t *traverse(skiplist_t *last_node, int value)
{
		while(last_node->n <= value)
		{
			printf("Value checked at index[%lu] = [%d]\n", last_node->index, last_node->n);
			if (last_node->n == value)
				return (last_node);
			last_node = last_node->next;
			if (last_node == NULL)
				break;
		}
		return (NULL);
}