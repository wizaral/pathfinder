#include "libmx.h"

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = str ? mx_strlen(str) - 1: 0;
    char *new_str = NULL;

    if (str) {
        for (; mx_isspace(str[start]); ++start);
        for (; mx_isspace(str[end]) && end > start; --end);
        new_str = mx_strnew(end > start ? end - start + 1 : 0);
        mx_strncpy(new_str, str + start, end - start + 1);
    }
    return new_str;
}
