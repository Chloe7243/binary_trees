#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t fdepth, sdepth;
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t*)first);
	fdepth = binary_tree_depth(first);
	sdepth = binary_tree_depth(second);

	if (fdepth > sdepth)
		return (binary_trees_ancestor(first->parent, second));
	else if (fdepth < sdepth)
		return (binary_trees_ancestor(first, second->parent));
	else
	{
		if (first->parent == second->parent)
			return (first->parent);
		binary_trees_ancestor(first->parent, second->parent);
	}
	return (NULL);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to measure the depth of
 *
 * Return: depth of the node in tree
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree || !tree->parent)
		return (depth);

	depth += (1 + binary_tree_depth(tree->parent));

	return (depth);
}
