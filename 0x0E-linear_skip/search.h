#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *head, int value);
skiplist_t *traverse(skiplist_t *last_node, int value);

#endif /* _SEARCH_H_ */
