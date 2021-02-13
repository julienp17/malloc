/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** realloc
*/

#include <string.h>
#include "my_malloc.h"

static bool can_shrink(const mem_block_t *block, const size_t new_size);
static bool can_expand(const mem_block_t *block, const size_t new_size);

void *realloc(void *ptr, size_t size)
{
    mem_block_t *block = NULL;

    if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    }
    block = ptr - sizeof(mem_block_t);
    if (block->len == size)
        return ptr;
    if (can_realloc(block, size)) {
        memcpy(ptr + size, (void *)block->next, sizeof(mem_block_t));
        block->len = size;
        return ptr;
    } else {
        free(ptr);
        return malloc(size);
    }
}

bool can_realloc(const mem_block_t *block, const size_t new_size)
{
    return can_shrink(block, new_size) || can_expand(block, new_size);
}

static bool can_shrink(const mem_block_t *block, const size_t new_size)
{
    return block->len > new_size;
}

static bool can_expand(const mem_block_t *block, const size_t new_size)
{
    return (
        block->next != NULL
        && block->next->is_free
        && new_size <= block->len + sizeof(mem_block_t) + block->next->len
    );
}