#include "libmx.h"

static inline int get_length(const char *s, char c) {
    int len = 0;

    for (; s[len] && s[len] != c; ++len);
    return len;
}

char **mx_strsplit(const char *s, char c) {
    int words = mx_count_words(s, c);
    char **result = s ? (char **)malloc(sizeof(char *) * (words + 1)) : NULL;

    if (s && result) {
        for (int i = 0, j = 0, len; s[j]; ++j) {
            if (s[j] != c) {
                len = get_length(s + j, c);
                result[i++] = mx_strndup(s + j, len);
                j += len;
            }
        }
        result[words] = NULL;
    }
    return result;
}
