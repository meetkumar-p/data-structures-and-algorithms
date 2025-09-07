#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "sort.h"

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

SUPPRESS_UNUSED

/**
 * @brief Create a stack and push, pop, peek, check if it is empty, get size, and print it.
 *
 */
static void test_stack(void)
{
    // create a stack
    Stack *stack = stack_init();

    // seed the random number generator
    srandom(SEED);

    printf("stack_is_empty(...) before pushing any items to stack = %s\n\r",
           stack_is_empty(stack) ? "true" : "false");

    for(int32_t count = 0; count < 10; count++)
    {
        static int32_t num;

        num = (int32_t)random();
        stack_push(stack, num);
    }

    printf("stack_is_empty(...) after pushing items to stack = %s\n\r",
           stack_is_empty(stack) ? "true" : "false");
    printf("stack_size(...) = %zu\n\r", stack_size(stack));
    stack_print(stack);
    printf("stack_size(...) = %zu\n\r", stack_size(stack));
    printf("stack_peek(...) = %d\n\r", stack_peek(stack));
    printf("stack_pop(...) = %d\n\r", stack_pop(stack));
    printf("stack_size(...) = %zu\n\r", stack_size(stack));
    stack_print(stack);

    for(int32_t count = 0; count < 6; count++)
    {
        printf("stack_pop(...) = %d\n\r", stack_pop(stack));
    }

    printf("stack_size(...) = %zu\n\r", stack_size(stack));
    stack_print(stack);

    stack_free(&stack);
}

SUPPRESS_UNUSED

/**
 * @brief Create a queue and enqueue, dequeue, peek, check if it is empty, get size, and print it.
 *
 */
static void test_queue(void)
{
    // create a queue
    Queue *queue = queue_init();

    // seed the random number generator
    srandom(SEED);

    printf("queue_is_empty(...) before pushing any element to queue = %s\n\r",
           queue_is_empty(queue) ? "true" : "false");

    for(int32_t count = 0; count < 10; count++)
    {
        static int32_t element;

        element = (int32_t)random();
        queue_enqueue(queue, element);
    }

    printf("queue_is_empty(...) after pushing elements to queue = %s\n\r",
           queue_is_empty(queue) ? "true" : "false");
    printf("queue_size(...) = %zu\n\r", queue_size(queue));
    queue_print(queue);
    printf("queue_size(...) = %zu\n\r", queue_size(queue));
    printf("queue_peek(...) = %d\n\r", queue_peek(queue));
    printf("queue_dequeue(...) = %d\n\r", queue_dequeue(queue));
    printf("queue_size(...) = %zu\n\r", queue_size(queue));
    queue_print(queue);

    for(int32_t count = 0; count < 8; count++)
    {
        printf("queue_dequeue(...) = %d\n\r", queue_dequeue(queue));
    }

    printf("queue_size(...) = %zu\n\r", queue_size(queue));
    queue_print(queue);

    queue_free(&queue);
}

SUPPRESS_UNUSED

/**
 * @brief Create an array of pseudo-random values, print it, sort it, and print the sorted array.
 *
 */
static void test_bubble_sort(void)
{
    // seed the random number generator
    srandom(SEED);

    // create an array of values
    size_t size = 42;
    int32_t array[size];
    for(size_t idx = 0; idx < size; idx++)
    {
        array[idx] = (int32_t)random();
    }

    // print the unsorted array
    printf("Unsorted array:\n\r");
    for(size_t idx = 0; idx < size; idx++)
    {
        printf("%d\n\r", array[idx]);
    }

    // sort the array
    sort_bubble(array, size);

    // print the sorted array
    printf("Sorted array:\n\r");
    for(size_t idx = 0; idx < size; idx++)
    {
        printf("%d\n\r", array[idx]);
    }
}

int main(void)
{
    TEST();

    return 0;
}
