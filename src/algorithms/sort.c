#include "sort.h"

#include <stddef.h>
#include <stdint.h>

void sort_bubble(int32_t *array, const size_t size)
{
    for(size_t i = size - 1; i > 0; i--)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(array[j] > array[j + 1])
            {
                int32_t temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sort_selection(int32_t *array, const size_t size)
{
    for(size_t i = 0; i < size - 1; i++)
    {
        size_t min_idx = i;

        for(size_t j = i + 1; j < size; j++)
        {
            if(array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        int32_t min_val = array[min_idx];
        array[min_idx] = array[i];
        array[i] = min_val;
    }
}

void sort_insertion(int32_t *array, const size_t size)
{
    for(size_t i = 1; i < size; i++)
    {
        size_t insert_idx = i;
        int32_t curr_val = array[i];

        for(size_t j = 0; (j < i) && (array[i - 1 - j] > curr_val); j++)
        {
            array[i - 1 - j + 1] = array[i - 1 - j];
            insert_idx = i - 1 - j;
        }

        array[insert_idx] = curr_val;
    }
}

/**
 * @brief Utility function of merge sort algorithm that recursively divides `array` into two
 * sub-arrays before calling another utility function to merge the sub-arrays into one sorted
 * array/sub-array.
 *
 * @param array     Array/Sub-array to be sorted.
 * @param idx_left  Left index of array/sub-array.
 * @param idx_right Right index of array/sub-array.
 */
static void sort_merge_util(int32_t *array, size_t idx_left, size_t idx_right);

/**
 * @brief Utility function of merge sort algorithm that merges two sub-arrays into one sorted array
 * with its elements in ascending order.
 *
 * @param array     Array/Sub-array to be sorted.
 * @param idx_left  Left index of array/sub-array.
 * @param idx_mid   Middle index of array/sub-array between `idx_left` and `idx_right`.
 * @param idx_right Right index of array/sub-array.
 */
static void sort_merge_merge(int32_t *array, size_t idx_left, size_t idx_mid, size_t idx_right);

void sort_merge(int32_t *array, const size_t size)
{
    sort_merge_util(array, 0, size - 1);
}

static void sort_merge_util(int32_t *array, size_t idx_left, size_t idx_right)
{
    if(idx_left < idx_right)
    {
        size_t idx_mid = idx_left + (idx_right - idx_left) / 2;

        sort_merge_util(array, idx_left, idx_mid);
        sort_merge_util(array, idx_mid + 1, idx_right);

        sort_merge_merge(array, idx_left, idx_mid, idx_right);
    }
}

static void sort_merge_merge(int32_t *array, size_t idx_left, size_t idx_mid, size_t idx_right)
{
    size_t i, j, k;

    size_t size_left = idx_mid - idx_left + 1;
    size_t size_right = idx_right - idx_mid;

    // duplicate data to auxiliary arrays
    int32_t array_left[size_left], array_right[size_right];
    for(i = 0; i < size_left; i++)
    {
        array_left[i] = array[idx_left + i];
    }
    for(j = 0; j < size_right; j++)
    {
        array_right[j] = array[idx_mid + 1 + j];
    }

    // sort auxiliary arrays into main array
    i = 0;
    j = 0;
    k = idx_left;
    while(i < size_left && j < size_right)
    {
        if(array_left[i] <= array_right[j])
        {
            array[k++] = array_left[i++];
        }
        else
        {
            array[k++] = array_right[j++];
        }
    }
    while(i < size_left)
    {
        array[k++] = array_left[i++];
    }
    while(j < size_right)
    {
        array[k++] = array_right[j++];
    }
}
