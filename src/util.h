#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>

int *_copy_column(int **solution, int col, int dim);
void _assign_solution_rows(int **solution, int **all_combo,
                           int *row, int dim);
int *read_input16(const char *input);
int **get_grid44(const int *input, int **all_combo, int *flag);
bool _check_unique(const int *arr, int dim);
int _check_appearance(const int *line, int dim);
int *_make_one_line(int *i, int dim);

#endif
