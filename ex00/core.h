#include <unistd.h>

void _solve_core44(const int *input, int **solution);

void _solve_core44(const int *input, int **solution)
{
    int row;
    int col;

    row = 0;
    // TODO: complete core funtion
    write(1, "WARNING: solution not implemented.\n", 35);
    while (row <= 3)
    {
        if (input[0] == -1)
            col = -1;
        else
            col = 0;
        while (col <= 3)
        {
            solution[row][col] = 4;
            col++;
        }
        row++;
    }
}