#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * @brief `Stack` data structure.
 *
 */
typedef struct Stack Stack;

/**
 * @brief Create and initialize a `Stack` data structure.
 *
 * @return `Stack*` Pointer to new `Stack` data structure.
 */
Stack *stack_init();

/**
 * @brief Add a new item at the top of stack.
 *
 * @param stack `Stack` data structure.
 * @param item  Item to add to top of stack.
 */
void stack_push(Stack *const stack, const int32_t item);

/**
 * @brief Remove and return item at the top of stack.
 *
 * @param stack         `Stack` data structure.
 *
 * @return `int32_t`    Item at top of stack.
 */
int32_t stack_pop(Stack *const stack);

/**
 * @brief Return item at the top of stack.
 *
 * @param stack         `Stack` data structure.
 *
 * @return `int32_t`    Item at top of stack.
 */
int32_t stack_peek(Stack *const stack);

/**
 * @brief Check if stack is empty.
 *
 * @param stack     `Stack` data structure.
 *
 * @return `bool`   Return `true` if stack is empty, `false` otherwise.
 */
bool stack_is_empty(Stack *const stack);

/**
 * @brief Find number of items in stack.
 *
 * @param stack     `Stack` data structure.
 *
 * @return `size_t` Number of items in stack.
 */
size_t stack_size(Stack *const stack);

/**
 * @brief Print a `Stack` data structure.
 *
 * @param stack `Stack` data structure.
 */
void stack_print(Stack *const stack);

/**
 * @brief Free stack from heap.
 *
 * @param stack `Stack` data structure.
 */
void stack_free(Stack **stack);

#endif  // STACK_H_
