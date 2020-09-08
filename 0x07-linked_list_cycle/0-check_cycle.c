#include "lists.h"


/**
 * check_cycle - Checks for a loop in a linked list
 * @list: The list to check
 * Return: 0 on no cycle, 1 on cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow  = list;
	listint_t *fast = list;

	while (fast && slow && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
