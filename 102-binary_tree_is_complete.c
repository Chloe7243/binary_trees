#include "binary_trees.h"

/**
 * btic_helper - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @level: the level of the tree to call func upon
 * Return: int
 */
int btic_helper(const binary_tree_t *tree, size_t level)
{
	if (level == 0)
		return (1);
	return (tree->left ? btic_helper(tree->left, level - 1) : 0);
	return (tree->left ? btic_helper(tree->left, level - 1) : 0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete = 0, i, t_height;

	if (!tree)
		return (is_complete);

	t_height = binary_tree_height(tree);
	for (i = 0; i <= t_height; i++)
		is_complete = btic_helper(tree, i);
	return (is_complete);
}

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
