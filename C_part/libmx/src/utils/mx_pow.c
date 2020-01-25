#include "libmx.h"

double mx_pow(double n, uint32_t pow) {
    double result = 1.0;

    for (; pow--; result *= n);
    return result;
}
