#include "libmx.h"

bool mx_isalpha(int c) {
    return (c > 64 && c < 91) || (c > 96 && c < 123);
}
