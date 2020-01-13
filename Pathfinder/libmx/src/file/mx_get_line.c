#include "libmx.h"

long long mx_get_line(char **lineptr, char delim, const int fd) {
    size_t len = 0;
    size_t lim = 16;

    if (read(fd, NULL, 0) < 0) {
        *lineptr = mx_realloc(*lineptr, 0);
        return -2;
    }

    *lineptr = (char *)mx_realloc(*lineptr, lim);

    for (; *lineptr; len += 1) {
        len >= lim ? *lineptr = (char *)mx_realloc(*lineptr, lim *= 2) : NULL;
        *lineptr ? read(fd, *lineptr + len, 1) : -1;

        if (*lineptr && (*lineptr)[len] == delim) {
            ++len;
            break;
        }
    }

    if (*lineptr && delim != '\0' && (*lineptr = (char *)mx_realloc(*lineptr, len + 1)))
        (*lineptr)[len] = '\0';
    return *lineptr ? mx_strlen(*lineptr) : -1;
}

#include <stdio.h>

int main() {
    char *str;
    int stream = open("txt.txt", 0);

    printf(":%lli:%zu:%s:\n", mx_read_line(&str, '1', stream), malloc_size(str), str);
    printf(":%lli:%zu:%s:\n", mx_read_line(&str, '\n', stream), malloc_size(str), str);
    printf(":%lli:%zu:%s:\n", mx_read_line(&str, '\0', stream), malloc_size(str), str);

    close(stream);
    free(str);

    system("leaks -q a.out");
}
