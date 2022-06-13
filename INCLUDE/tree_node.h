/******************************************************************************
* AUTHOR: Evangelos Kalimeris                                                 *
*                                                                             *
* DATE: 12/6/22                                                               *
*                                                                             *
* FILE NAME: tree_node.h                                                      *
******************************************************************************/

struct tree_node{
    int node_id;
    struct tree_node *l_child;
    struct tree_node *r_child;
};

struct  tree_node* tree_root;

/**
 * @brief Utility function, registers a new node. Used by main().
 * @param node_id The soldier's node_id
 * @return 1 on success, 0 on failure
 */
void register_node(int node_id);