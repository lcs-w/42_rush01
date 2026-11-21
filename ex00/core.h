#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void _core_solver44(const int *input, int **solution);
bool _validate_grid(const int *input, int **solution, int dim);
bool _validate_line(int side1, int side2, int *line, int dim);

void _core_solver44(const int *input, int **solution)
{
    int row;
    int col;

    row = 0;
    // TODO: complete core funtion
    write(1, "WARNING: solution not implemented.\n", 35);
    while (!_validate_grid(input, solution, 4))
    {
        // keep solving
    }
}

bool _validate_grid(const int *input, int **solution, int dim)
{
    int col;
    int row;

    if (dim != 4 || dim != 9)
        return (false);
    col = -1;
    row = -1;
    while (++row < dim)
    {
        if (!_validate_line(input[row + dim * 2], input[row + dim * 3], solution[row], dim))
            return (false);
    }
    while (++col < dim)
    {
        if (!_validate_line(
                input[col], input[col + dim],
                _copy_column(solution, col, 4), dim))
            return (false);
    }
    return (true);
}

bool _validate_line(int side1, int side2, int *line, int dim)
{
    int i;
    int tallest;
    int seen;

    i = -1;
    tallest = 0;
    seen = 0;
    while (++i < dim)
    {
        if (line[i] > tallest)
        {
            tallest = line[i];
            seen++;
        }
    }
    if (seen != side1)
        return (false);
    seen = 0;
    tallest = 0;
    while (--i > 0)
    {
        if (line[i] > tallest)
        {
            tallest = line[i];
            seen++;
        }
    }
    if (seen != side2)
        return (false);
    return (true);
}

int *_copy_column(int **solution, int col, int dim)
{
    int r;
    int *col_copy;

    r = 0;
    *col_copy = malloc(dim * sizeof(int));
    while (r < dim)
    {
        col_copy[r] = solution[r][col];
        r++;
    }
    return col_copy;
}