#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int lensub = str && sub && replace ? mx_strlen(sub) : 0;
    int lenrep = str && sub && replace ? mx_strlen(replace) : 0;
    int count = mx_count_substr(str, sub);
    char *result = NULL;

    if (str && sub && replace && count > 0) {
        result = mx_strnew(mx_strlen(str) + (lenrep - lensub) * count);

        for (int i = 0, j = 0; str[i];) {
            if (str[i] == *sub && mx_strncmp((char *)str + i, sub, lensub) == 0) {
                mx_strncpy((char *)result + j, replace, lenrep);
                i += lensub;
                j += lenrep;
            }
            else
                result[j++] = str[i++];
        }
    }
    else if (str && sub && replace && count == 0)
        result = mx_strdup(str);
    return result;
}
