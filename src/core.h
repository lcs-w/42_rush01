#ifndef CORE_H
#define CORE_H

void _core_solver44(const int *input, int **solution,
					int **all_combo, int *flag);
int _validate_grid(const int *input, int **solution, int dim);
int _validate_line(int side1, int side2, const int *line, int dim);
int _validate_side(int expected, const int *line, int dim, int direction);

#endif