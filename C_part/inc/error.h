#pragma once

void mx_throw_file_exist_error(const char *filename);
void mx_throw_file_empty_error(const char *filename);
void mx_throw_line_error(size_t num);
void mx_throw_amount_error();
void mx_throw_usage_error();
