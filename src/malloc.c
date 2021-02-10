/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include "my_malloc.h"

static mem_block_t *mem_block_wrapper(mem_block_t *new_mem_block);

void *malloc(size_t size)
{
    mem_block_t *head = mem_block_wrapper(NULL);

    if (size == 0)
        return NULL;
    if (head == NULL) {
        head = (mem_block_t *)sbrk(get_block_size(size));
    }
    return head;
}

size_t get_block_size(const size_t requested)
{
    int page_size = getpagesize();
    size_t used = sizeof(mem_block_t) + requested;

    if (requested == 0)
        return 0;
    else if (used / page_size == 0)
        return 2 * page_size;
    return 2 * page_size * ((used - 1) / page_size);
}

static mem_block_t *mem_block_wrapper(mem_block_t *new_mem_block)
{
    static mem_block_t *mem_block = NULL;

    if (new_mem_block)
        mem_block = new_mem_block;
    return mem_block;
}