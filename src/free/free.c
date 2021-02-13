/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** free
*/

#include "my_malloc.h"

void free(void *ptr)
{
    mem_block_t *block = NULL;

    if (ptr == NULL)
        return;
    block = ptr - sizeof(mem_block_t);
    block->is_free = true;
}