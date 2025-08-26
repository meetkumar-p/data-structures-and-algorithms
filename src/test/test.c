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
static void test_linked_list_singly(void)
{
    Linked_List_Singly_Node *linked_list = NULL;

    for(int32_t count = 0; count < 25; count++)
    {
        linked_list_singly_insert(&linked_list, count);
    }

    printf("Singly linked list after inserting 25 nodes at head\n\r");
    linked_list_singly_print(linked_list);

    Linked_List_Singly_Node *node_21 = linked_list_singly_find(linked_list, 21);
    linked_list_singly_insert_before(node_21, linked_list_singly_create(99));

    printf("\n\rSingly linked list after inserting node:99 before node:21\n\r");
    linked_list_singly_print(linked_list);

    linked_list_singly_delete(&linked_list);

    printf("\n\rSingly linked list after deleting first node at head\n\r");
    linked_list_singly_print(linked_list);

    linked_list_singly_insert(&linked_list, 9);

    printf("\n\rSingly linked list after inserting node:9 at head\n\r");
    linked_list_singly_print(linked_list);

    Linked_List_Singly_Node *node_9 = linked_list_singly_find(linked_list, 9);
    linked_list_singly_insert_before(node_9, linked_list_singly_create(42));

    printf(
        "\n\rSingly linked list after inserting node:42 before node:9 that is closest to head\n\r");
    linked_list_singly_print(linked_list);

    linked_list_singly_free(&linked_list);
}

int main(void)
{
    TEST();

    return 0;
}
