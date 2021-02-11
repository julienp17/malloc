/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** heap
*/

#include <unistd.h>
#include "my_malloc.h"

void grow_heap();

size_t get_heap_size(const size_t request)
{
    int page_size = getpagesize();
    size_t used = sizeof(mem_block_t) + request;

    if (request == 0)
        return 0;
    else if (used / page_size == 0)
        return 2 * page_size;
    return 2 * page_size * ((used - 1) / page_size);
}