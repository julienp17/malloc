/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** add_block
*/

#include "my_malloc.h"

void add_block(mem_block_t *block, const size_t size)
{
    block->is_free = false;
    if (can_add_free_block(block, size))
        add_free_block(block, size);
    block->len = size;
}

bool can_add_free_block(const mem_block_t *block, const size_t size)
{
    return block->len - size > sizeof(mem_block_t) + 1;
}

void add_free_block(mem_block_t *block, const size_t size)
{
    mem_block_t *free_block = (void *)block + sizeof(mem_block_t) + size;

    free_block->is_free = true;
    free_block->len = block->len - sizeof(mem_block_t) * 2 - size;
    free_block->next = block->next;
    block->next = free_block;
}

size_t get_used_size(mem_block_t *head)
{
    mem_block_t *block = head;
    size_t used = 0;

    while (block) {
        if (!(block->next == NULL && block->is_free))
            used += sizeof(mem_block_t) + block->len;
        block = block->next;
    }
    return used;
}