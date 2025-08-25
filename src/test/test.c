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

int main(void)
{
    TEST();

    return 0;
}
