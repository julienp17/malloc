/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include "my_malloc.h"

static mem_block_t *first_malloc(size_t size);
static bool block_is_available(const mem_block_t *block, const size_t request);

void *malloc(size_t size)
{
    mem_block_t *block = mem_block_wrapper(NULL);

    if (size == 0)
        return NULL;
    if (block == NULL)
        return first_malloc(size);
    while (!block_is_available(block, size))
        block = block->next;
    //TODO: block not available


    return block + sizeof(mem_block_t);
}

static mem_block_t *first_malloc(size_t size)
{
    mem_block_t *head = NULL;
    size_t heap_size = 0;

    heap_size = get_heap_size(size);
    head = (mem_block_t *)sbrk(heap_size);
    head->len = size;
    head->is_freed = false;
    head->next = head + (sizeof(mem_block_t) + head->len);
    head->next->len = heap_size - head->len - sizeof(mem_block_t) * 2;
    head->next->is_freed = true;
    head->next->next = NULL;
    mem_block_wrapper(head);
    return head;
}

static bool block_is_available(const mem_block_t *block, const size_t request)
{
    return (
        block != NULL
        && block->is_freed == true
        && block->len <= request
    );
}