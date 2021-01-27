#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - Finds a loop in a linked list
 * @head: The start of the list
 * Return: Null for no loop, or address of the looping node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = slow->next->next;

		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}
