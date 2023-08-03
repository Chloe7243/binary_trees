#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *l_child;

	if (!tree || !tree->left)
		return (NULL);

	l_child = tree->left;
	l_child->parent = tree->parent;
	tree->parent = l_child;
	tree->left = l_child->right;
	if (l_child->right)
		l_child->right->parent = tree;
	l_child->right = tree;

	return (l_child);
}
