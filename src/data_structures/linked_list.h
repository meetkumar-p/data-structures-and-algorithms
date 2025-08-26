#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdint.h>

/**
 * @brief Singly linked list node.
 *
 */
typedef struct Linked_List_Singly_Node Linked_List_Singly_Node;

/**
 * @brief Create a new singly linked list node.
 *
 * @param data                          Data for new singly linked list node.
 *
 * @return `Linked_List_Singly_Node`*   Pointer to new singly linked list node.
 */
Linked_List_Singly_Node *linked_list_singly_create(const int32_t data);

/**
 * @brief Insert a node at head of singly linked list.
 *
 * @param linked_list   Singly linked list.
 * @param data          Data to be inserted into singly linked list.
 */
void linked_list_singly_insert(Linked_List_Singly_Node **linked_list, const int32_t data);

/**
 * @brief Insert a new singly linked list node before a node.
 *
 * @param node      Node in singly linked list.
 * @param new_node  New node to be inserted into singly linked list.
 */
void linked_list_singly_insert_before(Linked_List_Singly_Node *const node,
                                      Linked_List_Singly_Node *const new_node);

/**
 * @brief Find singly linked list node with `data`.
 *
 * @param linked_list                   Singly linked list.
 * @param data                          Data to find in singly linked list.
 *
 * @return `Linked_List_Singly_Node`*   Pointer to singly linked list node with `data`.
 */
Linked_List_Singly_Node *linked_list_singly_find(Linked_List_Singly_Node const *linked_list,
                                                 const int32_t data);

/**
 * @brief Delete first node at head of singly linked list.
 *
 * @param linked_list   Singly linked list.
 */
void linked_list_singly_delete(Linked_List_Singly_Node **linked_list);

/**
 * @brief Free singly linked list.
 *
 * @param linked_list   Singly linked list.
 */
void linked_list_singly_free(Linked_List_Singly_Node **linked_list);

/**
 * @brief Print singly linked list.
 *
 * @param linked_list   Singly linked list.
 */
void linked_list_print(Linked_List_Singly_Node const *linked_list);

#endif  // LINKED_LIST_H_
