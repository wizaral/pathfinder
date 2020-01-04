#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str && sub && replace) {
        int len1 = mx_strlen(sub);
        int len2 = mx_strlen(replace);
        int count = mx_count_substr(str, sub);

        if (count > 0) {
            char *result = mx_strnew(mx_strlen(str) + (len2 - len1) * count);

            for (int i = 0; *str; ) {
                if (*str == *sub && mx_strncmp(str, sub, len1) == 0) {
                    mx_strncpy(result + i, replace, len2);
                    str += len1, i += len2;
                }
                else
                    result[i++] = *str++;
            }
            return result;
        }
    }
    return str && sub && replace ? mx_strdup(str) : NULL;
}
