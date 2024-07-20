#include <errorf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void *__errorf(const char *file, unsigned long line, const char * func, int status, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "%s:%lu:%s: ", file, line, func);
    vfprintf(stderr, fmt, args);
    fputc('\n', stderr);
    va_end(args);
    exit(status);
}