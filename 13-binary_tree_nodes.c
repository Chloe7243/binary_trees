#include "binary_trees.h"

/**
 * binary_tree_nodes - measures the nodes in a binary tree
 * @tree: tree to measure the nodes of
 *
 * Return: number of the node in tree
 *         0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (nodes);
	nodes += (tree->left || tree->right) ? 1 : 0;
	nodes += (binary_tree_nodes(tree->left));
	nodes += (binary_tree_nodes(tree->right));

	return (nodes);
}
