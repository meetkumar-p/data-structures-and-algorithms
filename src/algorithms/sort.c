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
