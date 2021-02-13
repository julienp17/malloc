/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** defragment
*/

#include "my_malloc.h"

void defragment(mem_block_t *head)
{
    mem_block_t *block = head;

    while (block) {
        if (can_defragment(block))
            defragment_block(block);
        block = block->next;
    }
}

bool can_defragment(const mem_block_t *block)
{
    return (
        block->is_free
        && block->next != NULL
        && block->next->is_free
    );
}

void defragment_block(mem_block_t *block)
{
    block->len += sizeof(mem_block_t) + block->next->len;
    block->next = block->next->next;
}