#include <stdlib.h>
#include <stdio.h>
#include "combo.h"
#include "util.h"

void _core_solver44(const int *input, int **solution,
                    int **all_combo, int *flag);
int _validate_grid(const int *input, int **solution, int dim);
int _validate_line(int side1, int side2, const int *line, int dim);
int _validate_side(int expected, const int *line, int dim, int direction);

int _validate_grid(const int *input, int **solution, int dim)
{
    int col;
    int row;
    int *col_copy;

    if (dim != 4 && dim != 9)
        return (0);
    col = -1;
    row = -1;
    while (++row < dim)
    {
        if (!_validate_line(input[row + dim * 2],
                            input[row + dim * 3], solution[row], dim))
            return (0);
    }
    while (++col < dim)
    {
        col_copy = _copy_column(solution, col, 4);
        if (!_validate_line(input[col], input[col + dim], col_copy, dim))
        {
            free(col_copy);
            return (0);
        }
        free(col_copy);
    }
    return (1);
}

int _validate_side(int expected, const int *line, int dim, int direction)
{
    int i;
    int tallest;
    int seen;

    if (direction == 1)
        i = 0;
    else
        i = dim - 1;
    tallest = 0;
    seen = 0;
    while (i >= 0 && i < dim)
    {
        if (line[i] > tallest)
        {
            tallest = line[i];
            seen++;
        }
        i += direction;
    }
    if (seen != expected)
        return (0);
    else
        return (1);
}

int _validate_line(int side1, int side2, const int *line, int dim)
{
    return (_validate_side(side1, line, dim, 1) && _validate_side(side2, line, dim, -1) && _check_appearance(line, dim));
}

void _core_solver44(const int *input, int **solution,
                    int **all_combo, int *flag)
{
    int row[4];

    row[0] = -1;
    while (++row[0] < 24)
    {
        row[1] = -1;
        while (++row[1] < 24)
        {
            row[2] = -1;
            while (++row[2] < 24)
            {
                row[3] = -1;
                while (++row[3] < 24)
                {
                    _assign_solution_rows4(solution, all_combo, row, 4);
                    if (_validate_grid(input, solution, 4))
                    {
                        *flag = 1;
                        return;
                    }
                }
            }
        }
    }
    printf("Solution not found.\n");
}
