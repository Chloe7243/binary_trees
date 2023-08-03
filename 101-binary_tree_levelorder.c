#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, t_height;

	if (!tree || !func)
		return;

	t_height = binary_tree_height(tree);

	for (i = 0; i <= t_height; i++)
		btlo_helper(tree, func, i);
}

/**
 * btlo_helper - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
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
