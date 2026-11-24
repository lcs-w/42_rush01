#ifndef COMBO_H
#define COMBO_H
#include <stdlib.h>

int *_make_one_line(int *i, int dim);
int _check_unique(int *i);
void get_all_combo24(int **line_collection);
void free_combo(int **combo);
int _check_appearance(const int *line, int dim);

#endif
