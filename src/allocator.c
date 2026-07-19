#include "../include/block.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>


static struct Block *head = NULL;

void *my_malloc(size_t size)
{

void *ptr = mmap(
    NULL,
    4096,
    PROT_READ | PROT_WRITE,
MAP_PRIVATE | MAP_ANONYMOUS,
    -1,
    0
);

if (ptr == MAP_FAILED) {
    perror("mmap failed");
    return NULL;
}

struct Block *block = (struct Block *)ptr;
block->size = 4096 - sizeof(struct Block);
block->is_free = 0;
block->next = NULL;
 
if (head == NULL){
head = block; }
 
return (void *)(block + 1);
 

}
