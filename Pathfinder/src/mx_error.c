#include "pathfinder.h"

void mx_throw_usage_error() {
    mx_printstr("usage: ./pathfinder [filename]\n", 2);
}

void mx_throw_file_exist_error(const char *filename) {
    mx_printstr("error: file ", 2);
    mx_printstr(filename, 2);
    mx_printstr(" does not exist\n", 2);
    exit(0);
}

void mx_throw_file_empty_error(const char *filename) {
    mx_printstr("error: file ", 2);
    mx_printstr(filename, 2);
    mx_printstr(" is empty\n", 2);
    exit(0);
}

void mx_throw_line_error(size_t num) {
    mx_printstr("error: line ", 2);
    mx_printunum(num, 2);
    mx_printstr(" is not valid\n", 2);
    exit(0);
}

void mx_throw_amount_error() {
    mx_printstr("error: invalid number of islands\n", 2);
    exit(0);
}
