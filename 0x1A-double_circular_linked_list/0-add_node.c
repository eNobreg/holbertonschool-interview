#include "list.h"
List *create_node(char *content);

/**
 * add_node_end - Add a node to the end of a linked list
 * @list: The linked list to add to
 * @str: The content to add to the linked list;
 * Return: The new node or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *last;
	List *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		new->next = *list;
		new->str = str;
		(*list)->prev = new;
		new->prev = last;
	}
	return (new);
}

/**
 * add_node_begin - Add a node to the end of a linked list
 * @list: The linked list to add to
 * @str: The content to add to the linked list;
 * Return: The new node or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *last;
	List *new;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		*list = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		new->prev = last;
		(*list)->prev = new;
		new->next = (*list);
		*list = new;
	}
	return (new);
}

/**
 * create_node - Creates a new node
 * @content: Content of the new node
 * Return: Null on fail or the new node's address
 */
List *create_node(char *content)
{
	List *new = malloc(sizeof(List));

	if (!new)
	{
		return (NULL);
	}

	new->str = content;

	new->next = NULL;
	new->prev = NULL;
	return (new);
}
