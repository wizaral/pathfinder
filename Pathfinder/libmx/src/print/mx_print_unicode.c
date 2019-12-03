#include "libmx.h"

// static void print_unicode(int c, int and, int or, int length) {
//     for (int j = length * 6, s = 0; j >= 0; write(1, &s, 1), j -= 6, s = 0)
//         s = j == length * 6 ? (c >> j & and) | or : (c >> j & 0x3F) | 0x80;
// }

// void mx_print_unicode(wchar_t c) {
//     if (c < 128)
//         print_unicode(c, 0x7F, 0x00, 0);
//     else if (c < 2048)
//         print_unicode(c, 0x1F, 0xC0, 1);
//     else if (c < 65536)
//         print_unicode(c, 0x0F, 0xE0, 2);
//     else
//         print_unicode(c, 0x07, 0xF0, 3);
// }

static void print_large(wchar_t c, char *cc, const int fd) {
    cc[0] = (c >> 18 & 0x07) | 0xF0;
    cc[1] = (c >> 12 & 0x3F) | 0x80;
    cc[2] = (c >> 6 & 0x3F) | 0x80;
    cc[3] = (c & 0x3F) | 0x80;
}

void mx_print_unicode(wchar_t c, const int fd) {
    char cc[5] = {0};

    if (fd >= 0) {
        if (c < 0x80) 
            cc[0] = c & 0x7F;
        else if (c < 0x0800) {
            cc[0] = (c >> 6 & 0x1F) | 0xC0;
            cc[1] = (c & 0x3F) | 0x80;
        }
        else if (c < 0x010000) {
            cc[0] = (c >> 12 & 0x0F) | 0xE0;
            cc[1] = (c >> 6 & 0x3F) | 0x80;
            cc[2] = (c & 0x3F) | 0x80;
        }
        else
            print_large(c, cc, fd);
        write(1, cc, mx_strlen(cc));
    }
}
