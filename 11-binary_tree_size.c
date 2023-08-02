#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a node in a binary tree
 * @tree: node to measure the size of
 *
 * Return: size of the node in tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (size);
	size = 1;
	size += (binary_tree_size(tree->left));
	size += (binary_tree_size(tree->right));

	return (size);
}
