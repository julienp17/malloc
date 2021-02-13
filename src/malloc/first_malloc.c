/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** first_malloc
*/

#include "my_malloc.h"

bool is_first_malloc(void)
{
    return mem_block_wrapper(NULL) == NULL;
}

void *first_malloc(const size_t size)
{
    mem_block_t *head = (mem_block_t *)grow_heap(0, size);

    head->len = get_growth_size(0, size);
    head->next = NULL;
    add_block(head, size);
    mem_block_wrapper(head);
    return (void *)head + sizeof(mem_block_t);
}