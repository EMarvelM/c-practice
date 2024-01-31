#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* allocate memory for node */
	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		perror("Malloc failed!\n");
		return (NULL);
	}

	/* Setting the value */
	new_node->n = value;

	if (parent != NULL)
	{
		if (parent->n > value)
		{
			/*Child should be at the left*/
			parent->left = new_node;
		}
		else if (parent->n < value)
		{
			parent->right = new_node;
		}
		else
		{
			if (parent->left == NULL)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
	}

	return (new_node);
}
