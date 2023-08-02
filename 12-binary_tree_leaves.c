#include "binary_trees.h"

/**
 * binary_tree_leaves - measures the leaves of a node in a binary tree
 * @tree: node to measure the leaves of
 *
 * Return: leaves of the node in tree
 *         0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (leaves);
	leaves += (tree->left || tree->right) ? 0 : 1;
	leaves += (binary_tree_leaves(tree->left));
	leaves += (binary_tree_leaves(tree->right));

	return (leaves);
}
