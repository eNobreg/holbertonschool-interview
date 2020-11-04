#include "binary_trees.h"

/**
 * sorted_array_to_avl - Main driver function for the program
 * @array: Sorted array to create the tree from
 * @size: Size of the given array
 * Return: The head node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head = NULL;

	head = recursive_helper(NULL, array, 0, size - 1);
	if (head == NULL)
		return (NULL);
	return (head);

}

/**
 * recursive_helper - Recusrive function to construct balanced BST
 * @parent: The parent node of the current node
 * @arr: The sorted arrray
 * @start: The start of the current subarray
 * @end: The end of the current subarray
 * Return: Null on error or the root node
 */
avl_t *recursive_helper(avl_t *parent, int *arr, int start, int end)
{
	int mid = 0;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = create_node(parent, arr[mid]);
	if (root == NULL)
		return (NULL);

	root->left = recursive_helper(root, arr, start, mid - 1);
	root->right = recursive_helper(root, arr, mid + 1, end);

	return (root);
}

/**
 * create_node - Creates a new node of avl_t
 * @parent: Parent of the created node
 * @value: value to assign created node
 * Return: The new node
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = parent;

	return (new_node);
}
