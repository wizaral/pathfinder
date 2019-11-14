#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    unsigned long pow = 1;
    int len = hex ? mx_strlen(hex) : 0;

    for (int j = len - 1; j >= 0; --j, pow *= 16) {
        if (hex[j] > 47 && hex[j] < 58)
            result += pow * (hex[j] - 48);
        else if(hex[j] > 64 && hex[j] < 71)
            result += pow * (hex[j] - 55);
        else if(hex[j] > 96 && hex[j] < 103)
            result += pow * (hex[j] - 87);
        else
            return 0;
    }
    return result;
}
