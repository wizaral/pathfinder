#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str && sub) {
        int len1 = mx_strlen(str);
        int len2 = mx_strlen(sub);
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
