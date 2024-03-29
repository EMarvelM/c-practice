#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: void
*/

void binary_tree_delete(binary_tree_t *tree)
{
	/* if tree is null do nothing */
	if (tree == NULL) return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	if (tree->left != NULL)
	{
		free(tree->left);
		tree->left = NULL;
	}
	if (tree->right != NULL)
	{
		free(tree->right);
		tree->right = NULL;
	}
}