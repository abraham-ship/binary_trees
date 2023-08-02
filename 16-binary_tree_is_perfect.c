#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL otherwise return height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return ((left_height >= right_height) ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_count - count nodes
 * @tree: pointer to root
 * Return: number of nodes
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_count(tree->left) + binary_tree_count(tree->right));
}


/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL otherwise 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, node_count, max_node_count;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	node_count = binary_tree_count(tree);
	max_node_count = (1 << height) - 1;

	return ((node_count == max_node_count) ? 1 : 0);
}
