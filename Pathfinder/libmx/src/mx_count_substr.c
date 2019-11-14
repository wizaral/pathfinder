#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int len1 = str && sub ? mx_strlen(str) : 0;
    int len2 = str && sub ? mx_strlen(sub) : 0;
    int result = 0;

    if (str && sub && len1 >= len2) {
        for (bool f; (str = mx_strchr(str, *sub)); str += f ? 1 : len2)
            if ((f = mx_strncmp(str, sub, len2)) == 0)
                ++result;
        return result;
    }
    return str && sub ? 0 : -1;
}
