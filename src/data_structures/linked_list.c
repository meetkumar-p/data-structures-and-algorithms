#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct Linked_List_Singly_Node
{
    int data;
    Linked_List_Singly_Node *next;
};

Linked_List_Singly_Node *linked_list_singly_create(const int32_t data)
{
    Linked_List_Singly_Node *node;
    node = (Linked_List_Singly_Node *)malloc(sizeof(Linked_List_Singly_Node));
    node->data = data;

    return node;
}

void linked_list_singly_insert(Linked_List_Singly_Node **linked_list, const int32_t data)
{
    Linked_List_Singly_Node *node = linked_list_singly_create(data);
    node->next = *linked_list;

    *linked_list = node;
}

void linked_list_singly_insert_before(Linked_List_Singly_Node *const node,
                                      Linked_List_Singly_Node *const new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

Linked_List_Singly_Node *linked_list_singly_find(Linked_List_Singly_Node const *linked_list,
                                                 const int32_t data)
{
    Linked_List_Singly_Node const *node = NULL;
    Linked_List_Singly_Node const *temp = linked_list;

    while(NULL == node && NULL != temp)
    {
        if(data == temp->data)
        {
            node = temp;
        }
        else
        {
            temp = temp->next;
        }
    }

    return (Linked_List_Singly_Node *)node;
}

void linked_list_singly_delete(Linked_List_Singly_Node **linked_list)
{
    if(NULL == *linked_list)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }
    else
    {
        Linked_List_Singly_Node *temp = *linked_list;
        *linked_list = temp->next;
        free(temp);
    }
}

void linked_list_singly_free(Linked_List_Singly_Node **linked_list)
{
    if(NULL == *linked_list)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }

    while(NULL != *linked_list)
    {
        Linked_List_Singly_Node *temp = *linked_list;
        *linked_list = temp->next;
        free(temp);
    }
}

void linked_list_print(Linked_List_Singly_Node const *linked_list)
{
    Linked_List_Singly_Node const *node = linked_list;

    if(NULL != linked_list)
    {
        printf("%d", node->data);
        while(NULL != node->next)
        {
            node = node->next;
            printf(" -> %d", node->data);
        }
        printf("\n\r");
    }
    else
    {
        printf("Linked list is empty, nothing to print\n\r");
    }
}
