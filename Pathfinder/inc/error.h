#ifndef ERROR_H
#define ERROR_H

void mx_throw_usage_error();
void mx_throw_file_exist_error(const char *filename);
void mx_throw_file_empty_error(const char *filename);
void mx_throw_line_error(int num);
void mx_throw_amount_error();

#endif
