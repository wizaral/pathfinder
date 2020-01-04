#include "libmx.h"

double mx_pow(double n, unsigned pow) {
    double result = 1.0;

    for (; pow--; result *= n);
    return result;
}
