#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str && sub) {
        size_t len1 = mx_strlen(str);
        size_t len2 = mx_strlen(sub);
        int result = 0;

        if (len1 >= len2) {
            for (bool f; (str = mx_strchr(str, *sub)); str += f ? 1 : len2)
                if ((f = mx_strncmp(str, sub, len2)) == 0)
                    ++result;
            return result;
        }
    }
    return str && sub ? 0 : -1;
}
