#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp = str ? mx_strnew(mx_strlen(str)) : NULL;
    char *result = NULL;
    int j = 0;

    if (temp) {
        for (int i = 0; str[i]; temp[j] = str[i], ++i, ++j)
            if (mx_isspace(str[i]))
                for (temp[j++] = ' '; mx_isspace(str[i]); ++i);
        result = mx_strtrim(temp);
        free(temp);
    }
    return result;
}
