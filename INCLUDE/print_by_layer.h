/******************************************************************************
* AUTHOR: Evangelos Kalimeris                                                 *
*                                                                             *
* DATE: 12/6/22                                                               *
*                                                                             *
* FILE NAME: print_by_layer.h                                                 *
******************************************************************************/

#include <stdio.h>
#include "tree_node.h"

// Max nodes supported for layer printing
#define MAX 100

/**
 * Utility function, used by print_by_level().
 */
void insert(void * data);

/**
 * Utility function, used by print_by_level().
 */
void * removeData();

/**
 * @brief Prints each of a tree's nodes, one level at a time. From the
 *        leftmost node, to the rightmost.
 * @param root The tree root
 */
void print_by_level(struct tree_node *root);