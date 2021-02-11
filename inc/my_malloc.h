/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct mem_block
{
    bool is_free;
    size_t len;
    struct mem_block *next;
} mem_block_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

size_t get_heap_size(const size_t requested);
mem_block_t *mem_block_wrapper(mem_block_t *new_mem_block);

#endif