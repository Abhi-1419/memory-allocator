#include <stdio.h>
#include "block.h"

int main(void)
{
    char *a = my_malloc(100);
    char *b = my_malloc(200);

    printf("a = %p\n", a);
    printf("b = %p\n", b);

    my_free(a);
    my_free(b);

    char *c = my_malloc(250);

    printf("c = %p\n", c);

    return 0;
}
