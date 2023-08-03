#include "binary_trees.h"

/**
 * binary_tree_is_full - measures if the binary tree is full
 * @tree: tree to measure the fullness of
 *
 * Return: number of the node in tree
 *         0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 0;

	if (!tree)
		return (is_full);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		is_full = (binary_tree_is_full(tree->left));
		is_full = (binary_tree_is_full(tree->right));
	}

	return (is_full);
}
