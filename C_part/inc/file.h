#pragma once

#include "graph.h"

typedef struct s_file {
    char *file;         // pointer with stored file input
    char *copy;         // same file pointer that should not change
    t_pair src;         // struct for connect with first island
    t_pair dst;         // struct for connect with second island
    size_t line;        // current line of file
    char **names;       // temporary array of stored islands from line
    size_t cntr;        // counter of current amount of islands
    uint64_t full_len;  // sum of all lengths in file
} t_file;

/*
* returns value in first line or exit from program in invalid cases
* main function for parsing file (includes loop for every line of file)
* function for reading and cheking islands in line
* function for reading and cheking distance in line
*/

size_t mx_check_file(const char *filename);
void mx_parse_file(t_info *info, t_file *file);
size_t mx_check_island(t_info *info, t_file *file, char delim);
int mx_parse_distance(t_file *file);
