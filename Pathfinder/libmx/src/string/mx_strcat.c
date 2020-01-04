#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);

    for (int i = 0; i < len2; ++i)
        s1[i + len1] = s2[i];
    s1[len1 + len2] = '\0';
    return s1;
}
