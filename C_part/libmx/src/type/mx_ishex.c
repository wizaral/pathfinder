#include "libmx.h"

bool mx_ishex(int c) {
    return (c > 47 && c < 58) || (c > 64 && c < 71) || (c > 96 && c < 103);
}
