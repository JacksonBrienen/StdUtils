#include <cstring.h>
#include <errorf.h>

cstr_t cstring_init(const char *str) {
    size_t length = strlen(str);
    size_t *ptr = (size_t *)s_malloc(sizeof(size_t) + length + 1);
    *ptr = length;
    strcpy((char *)(ptr + 1), str);
    return (cstr_t)(ptr + 1);
}

cstr_t cstring_len_init(const char *str, size_t len) {
    size_t *ptr;
    size_t str_len = strlen(str);
    size_t mem_size = sizeof(size_t) + len + 1;
    if(str_len < len) {
        ptr = (size_t *)s_calloc(1, mem_size);
        *ptr = str_len;
        strcpy((char *)(ptr + 1), str);
    } else {
        ptr = (size_t *)s_malloc(mem_size);
        *ptr = len;
        strncpy((char *)(ptr + 1), str, len);
    }
    return (cstr_t)(ptr + 1);
}

size_t cstrlen(cstr_t cstr) {
    return *((size_t*)cstr - 1);
}