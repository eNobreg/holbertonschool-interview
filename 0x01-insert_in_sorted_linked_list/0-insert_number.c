#include "lists.h"
#include <stdlib.h>


/**
 * insert_node - Inserts a node in a singly linked list
 * @number: The value to add to the linked list
 * @head: The start of the linked list
 * Return: NULL or the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = number;
	new->next = NULL;

	if (number < current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (current->next)
	{
		if (current->next->n > number)
		{
			break;
		}
		current = current->next;
	}
	if (current == NULL)
	{
		return (NULL);
	}
	else
	{
		new->next = current->next;
		current->next = new;
	}
	return (new);
}
