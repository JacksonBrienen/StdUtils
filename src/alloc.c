#include <alloc.h>
#include <errorf.h>
#include <stdlib.h>

void *__s_malloc(size_t size, const char *file, unsigned long line, const char * func) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        __errorf(file, line, func, EXIT_FAILURE, "NULL Pointer Returned while allocating %lu bytes", size);
    }
    return ptr;
}

void *__s_realloc(void *ptr, size_t size, const char *file, unsigned long line, const char * func) {
    void *_ptr = realloc(ptr, size);
    if(_ptr == NULL) {
        __errorf(file, line, func, EXIT_FAILURE, "NULL pointer returned while allocating %lu bytes", size);
    }
    return _ptr;
}

void *__s_calloc(size_t nmemb, size_t size, const char *file, unsigned long line, const char * func) {
    if(size == 0) {
        __errorf(file, line, func, EXIT_FAILURE, "Calloc called with a size of 0");
    }
    void *ptr = calloc(nmemb, size);
    if(ptr == NULL) {
        __errorf(file, line, func, EXIT_FAILURE, "NULL pointer returned while allocating %lu elements of %lu bytes each", nmemb, size);
    }
    return ptr;
}