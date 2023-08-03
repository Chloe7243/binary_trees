#include "binary_trees.h"

/**
 * exponent - gets the result of raising the 1st arg to the pow of the 2nd arg
 * @base: base
 * @power: power
 * Return: int
 */

int exponent(int base, int power)
{
	if (power == 1)
		return (base);
	return (base * exponent(base, power - 1));
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
	int nodes, height, exp_nodes;

	if (!tree)
		return (0);

	nodes = binary_tree_size(tree);
	height = binary_tree_height(tree);
	exp_nodes = exponent(2, (height + 1)) - 1;

	if (nodes == exp_nodes || nodes == exp_nodes - (exponent(2, height) / 2))
		return (1);

	return (0);
}
