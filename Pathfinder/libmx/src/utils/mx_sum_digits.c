#include "libmx.h"

int mx_sum_digits(unsigned long long num) {
    int sum = 0;

    for (; num; sum += num % 10, num /= 10);
    return sum;
}
