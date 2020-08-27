#include "lists.h"
int palin_helper(listint_t **head, listint_t *node);

/**
 * is_palindrome - checks a palindrome
 * @head: List
 * Return: 1 or 0
 */

int is_palindrome(listint_t **head)
{
	int i = 0;

	i = palin_helper(head, *head);
	return (i);
}
/**
 * palin_helper - recursive function
 * @head: List
 * @node: node
 * Return: 0 or 1
 */
int palin_helper(listint_t **head, listint_t *node)
{
	int i = 0, j = 0;
	listint_t *current;

	if (head == NULL)
		return (1);

	current = node;
	if (current == NULL)
		return (1);

	i = palin_helper(head, current->next);
	if (i == 0)
		return (0);

	j = (current->n == (*head)->n);

	*head = (*head)->next;
	return (j);
}
