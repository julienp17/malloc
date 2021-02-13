/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** bestfit
*/

#include "my_malloc.h"

mem_block_t *find_best_block(const size_t size)
{
    mem_block_t *block = mem_block_wrapper(NULL);
    mem_block_t *best_block = NULL;

    while (block) {
        if (is_better_block(block, size, best_block))
            best_block = block;
        block = block->next;
    }
    return best_block;
}

bool is_better_block(const mem_block_t *block,
                   const size_t size,
                   const mem_block_t *best_block)
{
    return (
        block_is_available(block, size)
        && (
            best_block == NULL
            || block->len < best_block->len
        )
    );
}

bool block_is_available(const mem_block_t *block, const size_t size)
{
    return (
        block != NULL
        && block->is_free
        && block->len <= size
    );
}