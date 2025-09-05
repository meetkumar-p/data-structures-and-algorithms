#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

// clang-format off
#define STACK_CAPACITY_MIN              (8U)
// clang-format on

struct Stack
{
    int32_t *stack;
    size_t capacity;
    size_t size;
};

Stack *stack_init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->stack = (int32_t *)malloc(STACK_CAPACITY_MIN * sizeof(int32_t));
    stack->capacity = STACK_CAPACITY_MIN;
    stack->size = 0;

    return stack;
}

void stack_push(Stack *const stack, const int32_t item)
{
    if(stack->size == stack->capacity)
    {
        printf("Stack is full.\n\r");
        printf("Resizing stack...");

        // double stack capacity
        int32_t *new_stack;
        new_stack = realloc(stack->stack, (stack->capacity * 2 * sizeof(int32_t)));
        if(NULL == new_stack)
        {
            printf("\n\rStack resizing failed.\n\r");
        }
        else
        {
            stack->stack = new_stack;
            stack->capacity *= 2;

            printf("\n\rStack resizing complete.\n\r");
        }
    }

    if(stack->size != stack->capacity)
    {
        (stack->stack)[stack->size++] = item;
    }
}

int32_t stack_pop(Stack *const stack)
{
    int32_t ret_val;

    if(0 == stack->size)
    {
        printf("Stack is empty.\n\r");

        ret_val = -1;
    }
    else
    {
        ret_val = stack->stack[--stack->size];
    }

    // half stack capacity if only 1/4 of stack is occupied
    if(stack->size <= stack->capacity / 4 && stack->capacity / 2 >= STACK_CAPACITY_MIN)
    {
        printf("Stack is too big.\n\r");
        printf("Resizing stack...");

        int32_t *new_stack;
        new_stack = realloc(stack->stack, stack->capacity / 2 * sizeof(int32_t));

        if(NULL == new_stack)
        {
            printf("\n\rStack resizing failed.\n\r");
        }
        else
        {
            stack->stack = new_stack;
            stack->capacity /= 2;

            printf("\n\rStack resizing complete.\n\r");
        }
    }

    return ret_val;
}

int32_t stack_peek(Stack *const stack)
{
    int32_t ret_val;

    if(0 == stack->size)
    {
        printf("Stack is empty.\n\r");

        ret_val = -1;
    }
    else
    {
        ret_val = stack->stack[stack->size - 1];
    }

    return ret_val;
}

bool stack_is_empty(Stack *const stack)
{
    return (0 == stack->size);
}

size_t stack_size(Stack *const stack)
{
    return stack->size;
}

void stack_print(Stack *const stack)
{
    if(0 < stack->size)
    {
        printf("Stack top-to-bottom:\n\r");

        for(size_t idx = stack->size - 1; idx > 0; idx--)
        {
            printf("%d\n\r", stack->stack[idx]);
        }

        printf("%d\n\r", stack->stack[0]);
    }
    else
    {
        printf("Stack is empty.\n\r");
    }
}

void stack_free(Stack **stack)
{
    // free data structure used to store stack and Stack data structure itself
    free((*stack)->stack);
    free(*stack);

    *stack = NULL;
}
