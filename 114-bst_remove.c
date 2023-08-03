#include "binary_trees.h"

/**
 * left_most - finds the smallest node from a Binary Search Tree
 * @node: a pointer to the root node of the tree
 * Return: a pointer to the left_most node
 */

bst_t *left_most(bst_t *node)
{
	bst_t *leftmost = node;

	while (leftmost->left)
		leftmost = leftmost->left;
	return (leftmost);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removal
 *         NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = left_most(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
