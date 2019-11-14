#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count_words = 0;

    if (str) {
        while (*str) {
            for (; *str && *str == c; ++str);

            if (*str && *str != c) {
                for (; *str && *str != c; ++str);
                ++count_words;
            }
        }
    }
    return str ? count_words : -1;
}
