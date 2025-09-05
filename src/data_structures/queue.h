#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief `Queue` data structure.
 *
 */
typedef struct Queue Queue;

/**
 * @brief Create and initialize a `Queue` data structure.
 *
 * @return `Queue*` Pointer to new `Queue` data structure.
 */
Queue *queue_init();

/**
 * @brief Add an element to queue.
 *
 * @param queue     `Queue` data structure.
 * @param element   Element to add to back of queue.
 */
void queue_enqueue(Queue *const queue, const int32_t element);

/**
 * @brief Remove and return first (front) element from queue.
 *
 * @param queue         `Queue` data structure.
 *
 * @return `int32_t`    First element from queue.
 */
int32_t queue_dequeue(Queue *const queue);

/**
 * @brief Return first (front) element from queue.
 *
 * @param queue         `Queue` data structure.
 *
 * @return `int32_t`    First element from queue.
 */
int32_t queue_peek(Queue *const queue);

/**
 * @brief Check if queue is empty.
 *
 * @param queue `Queue` data structure.
 *
 * @return `bool`   Return `true` if queue is empty, `false` otherwise.
 */
bool queue_is_empty(Queue *const queue);

/**
 * @brief Find the number of elements in queue.
 *
 * @param queue     `Queue` data structure.
 *
 * @return `size_t` Number of elements in queue.
 */
size_t queue_size(Queue *const queue);

/**
 * @brief Print a `Queue` data structure.
 *
 * @param queue `Queue` data structure.
 */
void queue_print(Queue *const queue);

/**
 * @brief Free queue from heap.
 *
 * @param queue `Queue` data structure.
 */
void queue_free(Queue **queue);

#endif  // QUEUE_H_
