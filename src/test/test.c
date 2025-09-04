#include "linked_list.h"

#include "common/defines.h"

#include <stdio.h>
#include <stdlib.h>

SUPPRESS_UNUSED

/**
 * @brief Print a message to the console.
 *
 */
static void test_printf(void)
{
    printf("Hello World!\n\r");
}

SUPPRESS_UNUSED

/**
 * @brief Create, print, and delete a singly linked list.
 *
 */
static void test_ll_singly(void)
{
    LL_Singly_Node *ll = NULL;

    for(int32_t count = 0; count < 25; count++)
    {
        ll_singly_insert(&ll, count);
    }

    printf("Singly linked list after inserting 25 nodes at head\n\r");
    ll_singly_print(ll);

    LL_Singly_Node *node_21 = ll_singly_find(ll, 21);
    ll_singly_insert_before(node_21, ll_singly_create(99));

    printf("\n\rSingly linked list after inserting node:99 before node:21\n\r");
    ll_singly_print(ll);

    ll_singly_delete(&ll);

    printf("\n\rSingly linked list after deleting first node at head\n\r");
    ll_singly_print(ll);

    ll_singly_insert(&ll, 9);

    printf("\n\rSingly linked list after inserting node:9 at head\n\r");
    ll_singly_print(ll);

    LL_Singly_Node *node_9 = ll_singly_find(ll, 9);
    ll_singly_insert_before(node_9, ll_singly_create(42));

    printf(
        "\n\rSingly linked list after inserting node:42 before node:9 that is closest to head\n\r");
    ll_singly_print(ll);

    ll_singly_free(&ll);
}

SUPPRESS_UNUSED

/**
 * @brief Create, print, and delete a linked list.
 *
 */
static void test_ll(void)
{
    LL_Node *ll = NULL;

    for(int32_t count = 0; count < 25; count++)
    {
        ll_insert(&ll, count);
    }

    printf("Linked list after inserting 25 nodes at head\n\r");
    ll_print(ll);

    LL_Node *node_21 = ll_find(ll, 21);
    ll_insert_before(node_21, ll_create(99));

    printf("\n\rLinked list after inserting node:99 before node:21\n\r");
    ll_print(ll);

    ll_delete(&ll);

    printf("\n\rLinked list after deleting first node at head\n\r");
    ll_print(ll);

    LL_Node *node_5 = ll_find(ll, 5);
    ll_insert_after(node_5, ll_create(84));

    printf("\n\rLinked list after inserting node:84 after node:5\n\r");
    ll_print(ll);

    ll_insert(&ll, 9);

    printf("\n\rLinked list after inserting node:9 at head\n\r");
    ll_print(ll);

    LL_Node *node_9 = ll_find(ll, 9);
    ll_insert_before(node_9, ll_create(42));

    printf("\n\rLinked list after inserting node:42 before node:9 that is closest to head\n\r");
    ll_print(ll);

    ll_free(&ll);
}

int main(void)
{
    TEST();

    return 0;
}
