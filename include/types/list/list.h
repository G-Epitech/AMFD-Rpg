/*
** EPITECH PROJECT, 2023
** list.h
** File description:
** list functions
*/

#ifndef LIST_H_
    #define LIST_H_
    #include "types.h"

//==============================================
// NODE FUNCTIONS
//==============================================

/**
 * @brief Create a new int node
 * @param data Node data
 */
node_t *node_new(node_data_t data);

/**
 * @brief Unlink given node from its parent list
 * @param node The node to unlink
 */
void node_unlink(node_t *node);

/**
 * @brief Free the given node
 * @param node Node to free
 */
void node_free(node_t *node);

/**
 * @brief Swap the two given nodes
 * @param list List in which are nodes
 * @param node1 First node to swap
 * @param node2 Second node to swap
 */
void node_swap(list_t *list, node_t *node1, node_t *node2);


//==============================================
// LIST FUNCTIONS
//==============================================

/**
 * @brief Create a new list of int nodes
 */
list_t *list_new(void);

/**
 * @brief Remove the given node from list
 * @param list The list in which remove node
 * @param node The node to remove from list
 */
void list_remove(list_t *list, node_t *node);

/**
 * @brief Remove a node and free it
 * @param list The list in which delete node
 * @param node The node to delete from list
 */
void list_delete(list_t *list, node_t *node);

/**
 * @brief Free the given list and all its nodes
 * @param list The list to free
 */
void list_free(list_t *list);

/**
 * @brief Append a node after the ref node
 * @param list The list in which append the node
 * @param ref The reference node
 * @param node The node to append
 */
void list_append_after(list_t *list, node_t *ref, node_t *node);

/**
 * @brief Append a node before the ref node
 * @param list The list in which append the node
 * @param ref The reference node
 * @param node The node to append
 */
void list_append_before(list_t *list, node_t *ref, node_t *node);

/**
 * @brief Append a node at the end of list
 * @param list The list in which append the node
 * @param node The list in which append the node
 */
void list_append(list_t *list, node_t *node);

#endif /* !LIST_H_ */
