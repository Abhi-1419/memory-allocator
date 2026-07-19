#include <stdio.h>
#include "../include/block.h"

int main(void)
{
    char *p = my_malloc(100);

    if (p == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    p[0] = 'A';

    printf("%c\n", p[0]);

    return 0;
}
