#include <stdlib.h>
#include "../INCLUDE/tree_node.h"

/**
 * @brief Utility function, registers a new node. Used by main().
 * @param node_id The soldier's node_id
 * @return 1 on success, 0 on failure
 */
void register_node(int node_id) {
    struct tree_node *temp_node = tree_root, *new_node = malloc(sizeof(struct tree_node));
    //Initialize new node
    new_node->node_id = node_id;
    new_node->r_child = NULL;
    new_node->l_child = NULL;

    // BST is empty
    if (!tree_root) {
        tree_root = new_node;
    }
    else {
        // Find position of insertion
        while (1) {
            if (node_id > temp_node->node_id) {
                // Insert new node as right child
                if (!temp_node->r_child) {
                    temp_node->r_child = new_node;
                    break;
                }
                else
                    temp_node = temp_node->r_child;
            }
            else {
                // Insert new node as left child
                if (!temp_node->l_child) {
                    temp_node->l_child = new_node;
                    break;
                }
                else
                    temp_node = temp_node->l_child;
            }
        }
    }
}
