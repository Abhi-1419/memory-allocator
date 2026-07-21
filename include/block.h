#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>

struct Block
{
    size_t size;
    int is_free;
    struct Block *next;
};

void *my_malloc(size_t size);
void my_free(void *ptr);

#endif
