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
