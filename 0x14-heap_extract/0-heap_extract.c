#include "binary_trees.h"
void cascade_down(heap_t *root);
heap_t *move_last_node(heap_t *root);

/**
 * heap_extract - The driver for the heap extract
 * @root: The address to the root node
 * Return: The value of the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node = NULL;
	heap_t *holder = NULL;
	int root_value = 0;

	if (!(*root) || !(root))
		return (0);

	holder = *root;
	root_value = holder->n;
	last_node = move_last_node(holder);

	if (holder == last_node)
	{
		*root = NULL;
		free(holder);
		return (root_value);
	}

	if (last_node->parent->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	holder->n = last_node->n;

	cascade_down(holder);

	free(last_node);

	return (root_value);
}

/**
 * binary_tree_height - Returns the height of a binary tree
 * @root: Root node to count tree from
 * Return: The height of given tree or 0
 */
size_t binary_tree_height(heap_t *root)
{
	size_t left = 0;
	size_t right = 0;

	if (root == NULL)
	{
		return (0);
	}
	else
	{
		left = binary_tree_height(root->left) + 1;
		right = binary_tree_height(root->right) + 1;
	}

	return ((left >= right) ? left : right);
}

/**
 * binary_tree_size - Counts the total number of nodes in a binary tree
 * @root: Root of the binary tree
 * Return: The # of nodes in the tree
 */
size_t binary_tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + binary_tree_size(root->left) +
			binary_tree_size(root->right));
}

/**
 * cascade_down - Resort the binary tree so it is a heap
 * @root: Root of the tree to sort
 * Return: Nothing
 */
void cascade_down(heap_t *root)
{
	heap_t *largest_node = NULL;
	int temp;

	if (!root)
		return;

	if (root->right && root->right->n > root->left->n)
	{
		largest_node = root->right;
	}
	else if (root->left)
		largest_node = root->left;

	if (largest_node && largest_node->n > root->n)
	{
		temp = largest_node->n;
		largest_node->n = root->n;
		root->n = temp;
		cascade_down(largest_node);
	}
}

/**
 * move_last_node - Finds the last node inserted in a binary tree
 * @root: Root of the tree or subtree to search
 * Return: The last node or Null on fail
 */
heap_t *move_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	if (!root->left && !root->right)
		return (root);

	if (binary_tree_height(root->left) > binary_tree_height(root->right))
		return (move_last_node(root->left));

	if (binary_tree_size(root->left) > binary_tree_size(root->right))
		return (move_last_node(root->right));

	return (move_last_node(root->right));
}
