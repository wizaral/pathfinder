#include "libmx.h"

static void print_unicode(int c, int and, int or, int length) {
    for (int j = length * 6, s = 0; j >= 0; write(1, &s, 1), j -= 6, s = 0)
        s = j == length * 6 ? (c >> j & and) | or : (c >> j & 0x3F) | 0x80;
}

void mx_print_unicode(wchar_t c) {
    if (c < 128)
        print_unicode(c, 0x7F, 0x00, 0);
    else if (c < 2048)
        print_unicode(c, 0x1F, 0xC0, 1);
    else if (c < 65536)
        print_unicode(c, 0x0F, 0xE0, 2);
    else
        print_unicode(c, 0x07, 0xF0, 3);
}
