/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include "my_malloc.h"

void *malloc(size_t size)
{
    mem_block_t *block = NULL;

    if (size == 0)
        return NULL;
    if (is_first_malloc())
        return first_malloc(size);
    block = find_best_block(size);
    if (block) {
        add_block(block, size);
    } else {
        grow_heap(get_used_size(mem_block_wrapper(NULL)), size);
        return malloc(size);
    }
    return (void *)block + sizeof(mem_block_t);
}