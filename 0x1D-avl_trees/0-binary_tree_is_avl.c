#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);
int tree_balance(const binary_tree_t *tree);
int tree_balance_check(const binary_tree_t *tree);
int check_for_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: The tree to check from
 * Return: 1 if it is an AVL tree, 0 if not
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int total_balance;
	int bst;

	if (!tree)
		return (0);

	bst = check_for_bst(tree, INT_MIN, INT_MAX);

	if (bst == 1)
	{
		total_balance = tree_balance(tree);
		if (total_balance == 0)
			return (1);
	}
	return (0);
}

/**
 * get_height - Get's the height if given binary tree
 * @tree: Tree to check the height of
 * Return: Rotal height of the tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * tree_balance_check - Logic function of checking tree balance
 * @tree: Tree to calculate the balance of
 * Return: The balance factor of the given tree
 */
int tree_balance_check(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	return (left - right);

}

/**
 * tree_balance - Recursive driver function for checking balance of
 * all trees and subtrees of given tree
 * @tree: Starting node of the tree
 * Return: The overall balance factor of the tree
 */
int tree_balance(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);

	balance = tree_balance_check(tree);

	if (balance < -1 || balance > 1)
		return (balance);

	return (tree_balance(tree->left) || tree_balance(tree->right));
}

/**
 * check_for_bst - Checks if the given tree follows all  BST guidelines
 * for a BST
 * @tree: Tree to check
 * @min: Min value in the tree, INT_MIN in this case
 * @max: Max value of the tree, INT_MAX in this case;
 * Return: 1 or 0 dependiong on if it's a BST or not
 */
int check_for_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (check_for_bst(tree->left, min, tree->n - 1)
	&& check_for_bst(tree->right, tree->n + 1, max));
}
