/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** calloc
*/

#include <string.h>
#include <limits.h>
#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if (nmemb == 0 || size == 0 || nmemb * size > INT_MAX)
        return NULL;
    ptr = malloc(nmemb * size);
    memset(ptr, 0, nmemb * size);
    return ptr;
}