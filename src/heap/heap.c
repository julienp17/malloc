/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** heap
*/

#include <unistd.h>
#include "my_malloc.h"

void *grow_heap(const size_t used, const size_t request)
{
    return sbrk(get_growth_size(used, request));
}

size_t get_growth_size(const size_t used, const size_t request)
{
    const size_t growth = (size_t)getpagesize() * 2;
    size_t growth_size = 0;
    size_t total_size = 0;

    while (total_size < used)
        total_size += growth;
    while (total_size - used + growth_size < request)
        growth_size += growth;
    return growth_size;
}