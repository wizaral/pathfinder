#include "libmx.h"

uint64_t mx_hex_to_nbr(const char *hex) {
    uint64_t result = 0;
    uint64_t pow = 1;

    if (hex) {
        for (int64_t j = (int64_t)mx_strlen(hex) - 1; j >= 0; --j, pow *= 16) {
            if (hex[j] > 47 && hex[j] < 58)
                result += pow * (hex[j] - 48);
            else if(hex[j] > 64 && hex[j] < 71)
                result += pow * (hex[j] - 55);
            else if(hex[j] > 96 && hex[j] < 103)
                result += pow * (hex[j] - 87);
            else
                return 0;
        }
    }
    return result;
}
