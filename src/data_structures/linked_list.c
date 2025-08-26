#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct Linked_List_Singly_Node
{
    int data;
    Linked_List_Singly_Node *next;
};

struct Linked_List_Node
{
    int data;
    Linked_List_Node *next;
    Linked_List_Node *prev;
};

Linked_List_Singly_Node *linked_list_singly_create(const int32_t data)
{
    Linked_List_Singly_Node *node;
    node = (Linked_List_Singly_Node *)malloc(sizeof(Linked_List_Singly_Node));
    node->data = data;
    node->next = NULL;

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

void linked_list_singly_print(Linked_List_Singly_Node const *linked_list)
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

Linked_List_Node *linked_list_create(const int32_t data)
{
    Linked_List_Node *node;
    node = (Linked_List_Node *)malloc(sizeof(Linked_List_Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void linked_list_insert(Linked_List_Node **linked_list, const int32_t data)
{
    Linked_List_Node *node = linked_list_create(data);
    node->next = *linked_list;

    if(NULL != node->next)
    {
        node->next->prev = node;
    }

    *linked_list = node;
}

void linked_list_insert_before(Linked_List_Node *const node, Linked_List_Node *const new_node)
{
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;
    new_node->next->prev = new_node;
}

void linked_list_insert_after(Linked_List_Node *const node, Linked_List_Node *const new_node)
{
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev = new_node;
    new_node->prev->next = new_node;
}

Linked_List_Node *linked_list_find(Linked_List_Node const *linked_list, const int32_t data)
{
    Linked_List_Node const *node = NULL;
    Linked_List_Node const *temp = linked_list;

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

    return (Linked_List_Node *)node;
}

void linked_list_delete(Linked_List_Node **linked_list)
{
    if(NULL == *linked_list)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }
    else
    {
        Linked_List_Node *temp = *linked_list;
        *linked_list = temp->next;

        if(NULL != temp->next)
        {
            temp->next->prev = NULL;
        }

        free(temp);
    }
}

void linked_list_free(Linked_List_Node **linked_list)
{
    if(NULL == *linked_list)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }

    while(NULL != *linked_list)
    {
        Linked_List_Node *temp = *linked_list;
        *linked_list = temp->next;

        if(NULL != temp->next)
        {
            temp->next->prev = NULL;
        }

        free(temp);
    }
}

void linked_list_print(Linked_List_Node const *linked_list)
{
    Linked_List_Node const *node = linked_list;

    if(NULL != linked_list)
    {
        printf("%d", node->data);
        while(NULL != node->next)
        {
            node = node->next;
            printf(" <-> %d", node->data);
        }
        printf("\n\r");
    }
    else
    {
        printf("Linked list is empty, nothing to print\n\r");
    }
}
