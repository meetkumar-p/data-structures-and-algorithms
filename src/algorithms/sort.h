#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Use bubble sort algorithm to sort elements of an array in ascending order.
 *
 * @param array Array to be sorted.
 * @param size  Size of array.
 */
void sort_bubble(int32_t *array, const size_t size);

/**
 * @brief Use selection sort algorithm to sort elements of an array in ascending order.
 *
 * @param array Array to be sorted.
 * @param size  Size of array.
 */
void sort_selection(int32_t *array, const size_t size);

#endif  // SORT_H_
