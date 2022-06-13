/******************************************************************************
* AUTHOR: Evangelos Kalimeris                                                 *
*                                                                             *
* DATE: 12/6/22                                                               *
*                                                                             *
* FILE NAME: print_by_layer.c                                                 *
******************************************************************************/

#include "../INCLUDE/print_by_layer.h"

void *intArray[MAX];
int front = 0, rear = -1, itemCount = 0;

/**
 * Utility function, used by print_by_level().
 */
void insert(void * data) {
    if (itemCount != MAX) {
        if(rear == MAX-1)
            rear = -1;
        intArray[++rear] = data;
        itemCount++;
    }
}

/**
 * Utility function, used by print_by_level().
 */
void * removeData() {
    void * data = intArray[front++];

    if(front == MAX)
        front = 0;
    itemCount--;
    return data;
}

/**
 * @brief Prints each of a tree's nodes, one level at a time. From the
 *        leftmost node, to the rightmost.
 * @param root The tree root
 */
void print_by_level(struct tree_node *root) {
    int level = 1;
    if (!root) return;

    insert(root);

    while (itemCount) {
        int level_count = itemCount;
        printf("Level %i: ", level);
        while (level_count > 0) {
            struct tree_node *temp = intArray[front];
            printf("{%i}", temp->node_id);
            removeData();
            if (temp->l_child)
                insert(temp->l_child);
            if (temp->r_child)
                insert(temp->r_child);
            level_count--;
        }
        level++;
        puts("");
    }
}