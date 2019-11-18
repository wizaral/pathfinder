#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int len1 = str && sub ? mx_strlen(str) : 0;
    int len2 = str && sub ? mx_strlen(sub) : 0;

    if (!str || !sub)
        return -2;

    if (len1 >= len2)
        for (const char *copy = str; (str = mx_strchr(str, *sub)); ++str)
            if (mx_strncmp(str, sub, len2) == 0)
                return str - copy;
    return -1;
}
