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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	if (tree->right && tree->left)
		return (binary_tree_height(tree->left) ==
			binary_tree_height(tree->right) ? 1 : 0);

	return (0);
}
