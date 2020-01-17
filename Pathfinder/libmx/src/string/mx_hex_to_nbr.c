#include "libmx.h"

t_u64 mx_hex_to_nbr(const char *hex) {
    t_u64 result = 0;
    t_u64 pow = 1;

    if (hex) {
        for (t_i64 j = (t_i64)mx_strlen(hex) - 1; j >= 0; --j, pow *= 16) {
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
