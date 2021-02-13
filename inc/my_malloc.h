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

#define MIN(a, b)       ((a < b) ? a : b)

typedef struct mem_block
{
    bool is_free;
    size_t len;
    struct mem_block *next;
} mem_block_t;

mem_block_t *mem_block_wrapper(mem_block_t *new_mem_block);

void *malloc(size_t size);
bool is_first_malloc(void);
void *first_malloc(const size_t size);
void add_block(mem_block_t *block, const size_t size);
bool can_add_free_block(const mem_block_t *block, const size_t size);
void add_free_block(mem_block_t *block, const size_t size);
mem_block_t *find_best_block(const size_t size);
bool is_better_block(const mem_block_t *block,
                     const size_t size,
                     const mem_block_t *best_block);
bool block_is_available(const mem_block_t *block, const size_t request);
size_t get_used_size(mem_block_t *head);
void *grow_heap(const size_t used, const size_t request);
size_t get_growth_size(const size_t used, const size_t request);

void free(void *ptr);
void defragment(mem_block_t *head);
bool can_defragment(const mem_block_t *block);
void defragment_block(mem_block_t *block);

void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif