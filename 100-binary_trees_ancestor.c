#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in
 * a binary tree
 * @tree:  pointer to the node to measure the depth
 * Return: 0 if tree is NULL otherwise return depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - a function that finds the lowest common
 * ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: NULL if no commomn ancestor is found otherwise return
 * a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}
	while (first != second && first != NULL && second != NULL)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((first == second) ? (binary_tree_t *)first : NULL);
}
