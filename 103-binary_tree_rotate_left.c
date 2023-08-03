#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r_child;
	if (!tree || !tree->right)
		return (NULL);

	r_child = tree->right;
	r_child->parent = tree->parent;
	tree->parent = r_child;
	if (r_child->left)
	{
		tree->right = r_child->left;
		r_child->left->parent = tree;
	}
	else
		tree->right = NULL;
	r_child->left = tree;

	return (r_child);
}
