#include <unistd.h>

void write_digit(int digit, char *c);
void write_grid(int **solution, const int dim);

// write the single digit and c together
void write_digit(int digit, char *c)
{
    char buf;

    buf = digit + '0';
    write(1, &buf, 1);
    write(1, c, 1);
}

void write_grid(int **solution, const int dim)
{
    int row;
    int col;

    row = -1;
    while (++row <= dim - 1)
    {
        col = -1;
        while (++col <= dim - 1)
        {
            if (col < dim - 1 && solution[row][col] >= 0 && solution[row][col] <= 9)
            {
                write_digit(solution[row][col], " ");
            }
            else if (col == dim - 1 && solution[row][col] >= 0 && solution[row][col] <= 9)
            {
                write_digit(solution[row][col], "\n");
            }
        }
    }
}