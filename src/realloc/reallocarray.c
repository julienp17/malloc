/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu-20.04]
** File description:
** reallocarray
*/

#include <limits.h>
#include <errno.h>
#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb * size > INT_MAX) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(ptr, nmemb * size);
}