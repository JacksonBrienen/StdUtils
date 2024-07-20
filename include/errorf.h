#ifndef _ERRORF_H
#define _ERRORF_H

#include <stdlib.h>

#define errorf(fmt, ...) __errorf(__FILE__, __LINE__, __func__, EXIT_FAILURE, fmt, ##__VA_ARGS__)

#define errorfs(status, fmt, ...) __errorf(__FILE__, __LINE__, __func__, status, fmt, ##__VA_ARGS__)

void *__errorf(const char *file, unsigned long line, const char * func, int status, const char *fmt, ...);

#endif