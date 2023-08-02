#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0, rightheight = 0;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	leftheight += (1 + binary_tree_height(tree->left));
	rightheight += (1 + binary_tree_height(tree->right));

	return (leftheight >= rightheight ? leftheight : rightheight);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: tree to measure the balance of
 *
 * Return: balance of the tree
 *         0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	signed int lheight, rheight;

	if (!tree)
		return (0);
	lheight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rheight = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lheight - rheight);
}
