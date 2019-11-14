#include "libmx.h"

bool mx_isspace(int c) {
    return c == 32 || (c > 8 && c < 14);
}
