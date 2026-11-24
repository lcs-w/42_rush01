#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>

int *_copy_column(int **solution, int col, int dim);
void _assign_solution_rows4(int **solution, int **all_combo,
                            int *row, int dim);
int **_init_solution(int dim);
int *read_input16(const char *input);
int **get_grid44(const int *input, int **all_combo, int *flag);
int *_safe_malloc(size_t n);

#endif
