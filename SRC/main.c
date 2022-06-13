/******************************************************************************
* AUTHOR: Evangelos Kalimeris                                                 *
*                                                                             *
* DATE: 12/6/22                                                               *
*                                                                             *
* FILE NAME: main.c                                                           *
******************************************************************************/

#include "../INCLUDE/print_by_layer.h"

/**
 * Offers the desired functionality. Takes a BST and splits it to two new ones,
 * based on a user key. The new trees hold values less and more or equal than
 * the user key, respectively. The new trees retain the original tree's form.
 * @param initial_tree Provide the root of the tree to be split.
 * @param key User key
 * @param tree_less_than_key Provide a root for less values
 * @param tree_more_than_key Provide a root for more or equal values
 */
void split_BST(struct tree_node *initial_tree, int key, struct tree_node
        **tree_less_than_key, struct tree_node **tree_more_than_key)
{
    if (!initial_tree) return;

    if (initial_tree->node_id < key) {
        *tree_less_than_key = initial_tree;
        *tree_more_than_key = initial_tree->r_child;
        (*tree_less_than_key)->r_child = NULL;
        split_BST(*tree_more_than_key, key,
                  &(*tree_less_than_key)->r_child, tree_more_than_key);
    }
    else {
        *tree_more_than_key = initial_tree;
        *tree_less_than_key = initial_tree->l_child;
        (*tree_more_than_key)->l_child = NULL;
        split_BST(*tree_less_than_key, key, tree_less_than_key,
                  &(*tree_more_than_key)->l_child);
    }
}

/**
 * Function: main
 * ----------------------------------------------------------------------------
 *    For testing purposes. It creates an initial test tree and splits it to
 *    two. It also prints all 3 trees by levels, for visual inspection.
 *
 * Returns: 0 upon success
 */

/**
 * The main function is for testing purposes. It creates an initial test
 * tree and splits it to two. It also prints all 3 trees by levels, for visual
 * inspection.
 * @return 0 upon success
 */
int main() {

    // Provide dummy example nodes
    int arr[15] = {23, 5, 25, 3, 11, 24, 29, 1,
                   7, 19, 9, 17, 21, 15, 18};

    // Build an example tree on existing root
    for (int i = 0; i < 15; i++) {
        register_node(arr[i]);
    }
    // Print the initial tree
    puts("\nThe initial tree:");
    print_by_level(tree_root);

    // Set key with which to split tree
    int key = 18;

    // Initialize resulting subtrees
    struct tree_node *less, *more;

    // Split the tree
    split_BST(tree_root, key, &less, &more);

    // Nullify original root
    tree_root = NULL;

    // Print the subtrees
    printf("\nThe 1st subtree(all keys LESS than %i):\n", key);
    print_by_level(less);
    printf("\nThe 2nd subtree(all keys MORE than %i):\n", key);
    print_by_level(more);

    return 0;
}