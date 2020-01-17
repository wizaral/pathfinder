#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str && sub) {
        size_t len1 = mx_strlen(str);
        size_t len2 = mx_strlen(sub);

        if (len1 >= len2)
            for (const char *copy = str; (str = mx_strchr(str, *sub)); ++str)
                if (mx_strncmp(str, sub, len2) == 0)
                    return str - copy;
        return -1;
    }
    return -2;
}
