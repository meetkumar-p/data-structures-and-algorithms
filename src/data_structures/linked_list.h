#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdint.h>

/**
 * @brief Singly linked list node.
 *
 */
typedef struct LL_Singly_Node LL_Singly_Node;

/**
 * @brief Linked list node.
 *
 */
typedef struct LL_Node LL_Node;

/**
 * @brief Create a new singly linked list node.
 *
 * @param data                  Data for new singly linked list node.
 *
 * @return `LL_Singly_Node`*    Pointer to new singly linked list node.
 */
LL_Singly_Node *ll_singly_create(const int32_t data);

/**
 * @brief Insert a node at head of singly linked list.
 *
 * @param ll    Singly linked list.
 * @param data  Data to be inserted into singly linked list.
 */
void ll_singly_insert(LL_Singly_Node **ll, const int32_t data);

/**
 * @brief Insert a new singly linked list node before a node.
 *
 * @param node      Node in singly linked list.
 * @param new_node  New node to be inserted into singly linked list.
 */
void ll_singly_insert_before(LL_Singly_Node *const node, LL_Singly_Node *const new_node);

/**
 * @brief Find singly linked list node with `data`.
 *
 * @param ll                    Singly linked list.
 * @param data                  Data to find in singly linked list.
 *
 * @return `LL_Singly_Node`*    Pointer to singly linked list node with `data`.
 */
LL_Singly_Node *ll_singly_find(LL_Singly_Node const *ll, const int32_t data);

/**
 * @brief Delete first node at head of singly linked list.
 *
 * @param ll    Singly linked list.
 */
void ll_singly_delete(LL_Singly_Node **ll);

/**
 * @brief Free singly linked list.
 *
 * @param ll    Singly linked list.
 */
void ll_singly_free(LL_Singly_Node **ll);

/**
 * @brief Print singly linked list.
 *
 * @param ll    Singly linked list.
 */
void ll_singly_print(LL_Singly_Node const *ll);

/**
 * @brief Create a new linked list node.
 *
 * @param data          Data for new linked list node.
 *
 * @return `LL_Node`*   Pointer to new linked list node.
 */
LL_Node *ll_create(const int32_t data);

/**
 * @brief Insert a node at head of linked list.
 *
 * @param ll    Linked list.
 * @param data  Data to be inserted into linked list.
 */
void ll_insert(LL_Node **ll, const int32_t data);

/**
 * @brief Insert a new linked list node before a node.
 *
 * @param node      Node in linked list.
 * @param new_node  New node to be inserted into linked list.
 */
void ll_insert_before(LL_Node *const node, LL_Node *const new_node);

/**
 * @brief Insert a new linked list node after a node.
 *
 * @param node      Node in linked list.
 * @param new_node  New node to be inserted into linked list.
 */
void ll_insert_after(LL_Node *const node, LL_Node *const new_node);

/**
 * @brief Find linked list node with `data`.
 *
 * @param ll            Linked list.
 * @param data          Data to find in linked list.
 *
 * @return `LL_Node`*   Pointer to linked list node with `data`.
 */
LL_Node *ll_find(LL_Node const *ll, const int32_t data);

/**
 * @brief Delete first node at head of linked list.
 *
 * @param ll    Linked list.
 */
void ll_delete(LL_Node **ll);

/**
 * @brief Free linked list.
 *
 * @param ll    Linked list.
 */
void ll_free(LL_Node **ll);

/**
 * @brief Print linked list.
 *
 * @param ll    Linked list.
 */
void ll_print(LL_Node const *ll);

#endif  // LINKED_LIST_H_
