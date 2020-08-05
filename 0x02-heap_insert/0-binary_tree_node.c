#include "binary_trees.h"

/**
 * binary_tree_node - Adds a node to a binary tree
 * @parent: Parent node
 * @value: Value to insert
 * Return: The new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->right = NULL;
	new->left = NULL;

	return (new);
}
