#include "libmx.h"

static double precision(double x, double middle) {
    double stop = 16 - mx_get_num_length(middle, 10);
    double prec = 0.1;

    for (double i = 0; i < stop; ++i, prec /= 10) {
        while (middle * middle > x)
            middle -= prec;
        while (middle * middle < x)
            middle += prec;
    }
    return middle;
}

double mx_sqrt(double x) {
    double left = 0;
    double right = x > 0 ? x : 0;
    double middle = 0;
    double power;

    while (left <= right) {
        middle = left + (right - left) / 2;
        power = middle * middle;
        if (power < x)
            left = middle + 1;
        else if (power > x)
            right = middle - 1;
        else
            break;
    }
    return precision(x, middle);
}
