#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct LL_Singly_Node
{
    int data;
    LL_Singly_Node *next;
};

struct LL_Node
{
    int data;
    LL_Node *next;
    LL_Node *prev;
};

LL_Singly_Node *ll_singly_create(const int32_t data)
{
    LL_Singly_Node *node;
    node = (LL_Singly_Node *)malloc(sizeof(LL_Singly_Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void ll_singly_insert(LL_Singly_Node **ll, const int32_t data)
{
    LL_Singly_Node *node = ll_singly_create(data);
    node->next = *ll;

    *ll = node;
}

void ll_singly_insert_before(LL_Singly_Node *const node, LL_Singly_Node *const new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

LL_Singly_Node *ll_singly_find(LL_Singly_Node const *ll, const int32_t data)
{
    LL_Singly_Node const *node = NULL;
    LL_Singly_Node const *temp = ll;

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

    return (LL_Singly_Node *)node;
}

void ll_singly_delete(LL_Singly_Node **ll)
{
    if(NULL == *ll)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }
    else
    {
        LL_Singly_Node *temp = *ll;
        *ll = temp->next;
        free(temp);
    }
}

void ll_singly_free(LL_Singly_Node **ll)
{
    if(NULL == *ll)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }

    while(NULL != *ll)
    {
        LL_Singly_Node *temp = *ll;
        *ll = temp->next;
        free(temp);
    }
}

void ll_singly_print(LL_Singly_Node const *ll)
{
    LL_Singly_Node const *node = ll;

    if(NULL != ll)
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

LL_Node *ll_create(const int32_t data)
{
    LL_Node *node;
    node = (LL_Node *)malloc(sizeof(LL_Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void ll_insert(LL_Node **ll, const int32_t data)
{
    LL_Node *node = ll_create(data);
    node->next = *ll;

    if(NULL != node->next)
    {
        node->next->prev = node;
    }

    *ll = node;
}

void ll_insert_before(LL_Node *const node, LL_Node *const new_node)
{
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;
    new_node->next->prev = new_node;
}

void ll_insert_after(LL_Node *const node, LL_Node *const new_node)
{
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev = new_node;
    new_node->prev->next = new_node;
}

LL_Node *ll_find(LL_Node const *ll, const int32_t data)
{
    LL_Node const *node = NULL;
    LL_Node const *temp = ll;

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

    return (LL_Node *)node;
}

void ll_delete(LL_Node **ll)
{
    if(NULL == *ll)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }
    else
    {
        LL_Node *temp = *ll;
        *ll = temp->next;

        if(NULL != temp->next)
        {
            temp->next->prev = NULL;
        }

        free(temp);
    }
}

void ll_free(LL_Node **ll)
{
    if(NULL == *ll)
    {
        printf("Linked list is empty, nothing to free\n\r");
    }

    while(NULL != *ll)
    {
        LL_Node *temp = *ll;
        *ll = temp->next;

        if(NULL != temp->next)
        {
            temp->next->prev = NULL;
        }

        free(temp);
    }
}

void ll_print(LL_Node const *ll)
{
    LL_Node const *node = ll;

    if(NULL != ll)
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
