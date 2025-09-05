#include "queue.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// clang-format off
#define QUEUE_CAPACITY_MIN              (8U)
// clang-format on

struct Queue
{
    int32_t *queue;
    size_t capacity;
    size_t size;
    size_t front;
};

Queue *queue_init()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->queue = (int32_t *)malloc(QUEUE_CAPACITY_MIN * sizeof(int32_t));
    queue->capacity = QUEUE_CAPACITY_MIN;
    queue->size = 0;
    queue->front = 0;

    return queue;
}

void queue_enqueue(Queue *const queue, const int32_t element)
{
    if(queue->size == queue->capacity)
    {
        printf("Queue is full.\n\r");
        printf("Resizing queue ...");
        // double queue size
        int32_t *new_queue;
        new_queue = (int32_t *)malloc(queue->capacity * 2 * sizeof(int32_t));

        if(NULL == new_queue)
        {
            printf("\n\rQueue resizing failed.\n\r");
        }
        else
        {
            size_t new_size = 0;

            // move queue->queue to new_queue
            while(queue->size != new_size)
            {
                new_queue[new_size] = queue->queue[(queue->front + new_size) % queue->capacity];
                new_size++;
            }

            // free previous queue memory and track new, larger capacity, queue
            free(queue->queue);
            queue->queue = new_queue;

            queue->capacity *= 2;
            queue->size = new_size;
            queue->front = 0;

            printf("\n\rQueue resizing complete.\n\r");
        }
    }

    if(queue->size < queue->capacity)
    {
        queue->queue[(queue->front + queue->size++) % queue->capacity] = element;
    }
}

int32_t queue_dequeue(Queue *const queue)
{
    int ret_val;

    if(queue_is_empty(queue))
    {
        printf("Queue is empty.\n\r");

        ret_val = -1;
    }
    else
    {
        ret_val = queue->queue[queue->front];

        if(queue->size > 1)
        {
            queue->front = (queue->front + 1) % queue->capacity;
        }
        queue->size--;

        // half queue capacity if only 1/4 of queue is occupied
        if(queue->size < queue->capacity / 4 && queue->capacity / 2 >= QUEUE_CAPACITY_MIN)
        {
            printf("Queue is too big.\n\r");
            printf("Resizing queue ...");

            int32_t *new_queue;
            new_queue = (int32_t *)malloc(queue->capacity / 2 * sizeof(int32_t));

            if(NULL == new_queue)
            {
                printf("\n\rQueue resizing failed.\n\r");
            }
            else
            {
                size_t new_size = 0;

                // move queue->queue to new_queue
                while(queue->size != new_size)
                {
                    new_queue[new_size] = queue->queue[(queue->front + new_size) % queue->capacity];
                    new_size++;
                }

                // free previous queue memory and track new, smaller capacity, queue
                free(queue->queue);
                queue->queue = new_queue;

                queue->capacity /= 2;
                queue->size = new_size;
                queue->front = 0;

                printf("\n\rQueue resizing complete.\n\r");
            }
        }
    }

    return ret_val;
}

int32_t queue_peek(Queue *const queue)
{
    int ret_val;

    if(queue_is_empty(queue))
    {
        printf("Queue is empty.\n\r");

        ret_val = -1;
    }
    else
    {
        ret_val = queue->queue[queue->front];
    }

    return ret_val;
}

bool queue_is_empty(Queue *const queue)
{
    return (0 == queue->size);
}

size_t queue_size(Queue *const queue)
{
    return queue->size;
}

void queue_print(Queue *const queue)
{
    if(queue_is_empty(queue))
    {
        printf("Queue is empty.\n\r");
    }
    else
    {
        printf("Queue front-to-back:\n\r");

        for(size_t idx = 0; idx < queue->size; idx++)
        {
            printf("%d\n\r", queue->queue[(queue->front + idx) % queue->capacity]);
        }
    }
}

void queue_free(Queue **queue)
{
    // free data structure used to store queue and Queue data structure itself
    free((*queue)->queue);
    free(*queue);

    *queue = NULL;
}
