#include "../include/block.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

#include <stdint.h>
static struct Block *head = NULL;

void *my_malloc(size_t size)
{
struct Block *current = head;
while (current != NULL){ 

if(current->is_free == 1 && current->size >= size){

printf("Found a suitable block!\n");   
if(current->size >= size + sizeof(struct Block)){

struct Block *new_block =
    (struct Block *)((uint8_t *)current + sizeof(struct Block) + size);
}

}

current = current->next;
 }

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
