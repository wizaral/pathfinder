#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len1 = mx_strlen(haystack);
    int len2 = mx_strlen(needle);

    if (len2 == 0)
        return (char *)haystack;
    if (len1 >= len2)
        for (; (haystack = mx_strchr(haystack, *needle)); ++haystack)
            if (mx_strncmp(haystack, needle, len2) == 0)
                return (char *)haystack;
    return NULL;
}
