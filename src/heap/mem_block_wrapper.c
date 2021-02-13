/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** mem_block_wrapper
*/

#include "my_malloc.h"

mem_block_t *mem_block_wrapper(mem_block_t *new_mem_block)
{
    static mem_block_t *mem_block = NULL;

    if (new_mem_block)
        mem_block = new_mem_block;
    return mem_block;
}