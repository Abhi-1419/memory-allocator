#include "block.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
static struct Block *head = NULL;
void *my_malloc(size_t size)
{
    struct Block *current = head;

    while (current != NULL)
    {
        if (current->is_free && current->size >= size)
        {
            if (current->size >= size + sizeof(struct Block))
            {
                struct Block *new_block =
                    (struct Block *)((uint8_t *)current +
                                     sizeof(struct Block) + size);

                new_block->size =
                    current->size - sizeof(struct Block) - size;
                new_block->is_free = 1;
                new_block->next = current->next;

                current->next = new_block;
                current->size = size;
            }

            current->is_free = 0;
            return (void *)(current + 1);
        }

        current = current->next;
    }

    void *ptr = mmap(
        NULL,
        4096,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap failed");
        return NULL;
    }

    struct Block *block = (struct Block *)ptr;
    block->size = 4096 - sizeof(struct Block);
    block->is_free = 0;
    block->next = NULL;

    if (head == NULL)
    {
        head = block;
    }
    else
    {
        current = head;

        while (current->next != NULL)
            current = current->next;

        current->next = block;
    }

    return (void *)(block + 1);
}

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;

    struct Block *block = (struct Block *)ptr - 1;
    block->is_free = 1;

    struct Block *current = head;

    while (current != NULL)
    {
        if (current->next != NULL &&
            current->is_free &&
            current->next->is_free)
        {
            current->size += sizeof(struct Block) + current->next->size;
            current->next = current->next->next;
            continue;
        }

        current = current->next;
    }
}

