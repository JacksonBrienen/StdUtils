#ifndef __ALLOC_H
#define __ALLOC_H

#include <stddef.h>

#define s_malloc(__size) __s_malloc(__size, __FILE__, __LINE__, __func__)

void *__s_malloc(size_t size, const char *file, unsigned long line, const char * func);

#define s_realloc(__ptr, __size) __s_realloc(__ptr, __size, __FILE__, __LINE__, __func__)

void *__s_realloc(void *ptr, size_t size, const char *file, unsigned long line, const char * func);

#define s_calloc(__nmemb, __size) __s_calloc(__nmemb, __size, __FILE__, __LINE__, __func__)

void *__s_calloc(size_t nmemb, size_t size, const char *file, unsigned long line, const char * func);

#endif