/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <unistd.h>
#include "my_malloc.h"

static mem_block_t *first_malloc(size_t size);
static bool block_is_available(const mem_block_t *block, const size_t request);
static bool can_add_free_block(const mem_block_t *block, const size_t size);
static void add_free_block(mem_block_t *block, const size_t size);

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
    if (block) {
        block->is_free = false;
        if (can_add_free_block(block, size))
            add_free_block(block, size);
        block->len = size;
    } else {
        return NULL;
    }
    return block + sizeof(mem_block_t);
}

static mem_block_t *first_malloc(size_t size)
{
    mem_block_t *head = NULL;
    size_t heap_size = 0;

    heap_size = get_heap_size(size);
    head = (mem_block_t *)sbrk(heap_size);
    head->is_free = false;
    head->len = heap_size;
    head->next = NULL;
    add_free_block(head, size);
    return mem_block_wrapper(head);;
}

static bool block_is_available(const mem_block_t *block, const size_t size)
{
    return (
        block != NULL
        && block->is_free == true
        && block->len <= size
    );
}

static bool can_add_free_block(const mem_block_t *block, const size_t size)
{
    return block->len - size > sizeof(mem_block_t) + 1;
}

static void add_free_block(mem_block_t *block, const size_t size)
{
    mem_block_t *free_block = (void *)block + sizeof(mem_block_t) + size;

    free_block->is_free = true;
    free_block->len = block->len - sizeof(mem_block_t) * 2 - size;
    free_block->next = block->next;
    block->next = free_block;
}