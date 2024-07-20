#ifndef _CSTRING_H
#define _CSTRING_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "alloc.h"

typedef char * cstr_t;

cstr_t cstring_init(const char *str);

cstr_t cstring_len_init(const char *str, size_t len);

size_t cstrlen(const cstr_t cstr);

#define subcstr(__cstr, __from, __to) ((__to) < (__from)) ?                                                                 \
    errorf("Substring begining index larger than ending index for begining %lu and ending %lu", __from, __to) :             \
    ((__from) + (__to - __from) > cstrlen(__cstr)) ?                                                                        \
    errorf("Substring index out of bound for string of size %lu with indexes %lu to %lu", cstrlen(__cstr), __from, __to) :  \
    cstring_len_init((__cstr) + (__from), (__to) - (__from))

#define cstrapp(__cstr, __str)                                                      \
do {                                                                                \
    size_t * __ptr = ((size_t *)__cstr)-1;                                          \
    size_t __old_len = *__ptr;                                                      \
    size_t __new_len = strlen(__str) + __old_len;                                   \
    __ptr = (size_t *)s_realloc(__ptr, __new_len + sizeof(size_t) + 1);             \
    __cstr = (cstr_t)(__ptr + 1);                                                   \
    strcpy((__cstr) + __old_len, __str);                                            \
    *__ptr = __new_len;                                                             \
} while(0)

#define cstrpre(__str, __cstr)                                                      \
do {                                                                                \
    size_t * __ptr = ((size_t *)__cstr)-1;                                          \
    size_t __old_len = *__ptr;                                                      \
    size_t __str_len = strlen(__str);                                               \
    __ptr = (size_t *)s_realloc(__ptr, __old_len + __str_len + sizeof(size_t) + 1); \
    __cstr = (cstr_t)(__ptr + 1);                                                   \
    memcpy((__cstr) + __str_len, __cstr, __old_len + 1);                            \
    memcpy(__cstr, __str, __str_len);                                               \
    *__ptr = __old_len + __str_len;                                                 \
} while(0)

#endif