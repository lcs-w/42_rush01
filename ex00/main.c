#include <unistd.h>
#include <stdlib.h>
#include "core.h"

int *read_input16(const char *input);
int **get_grid44(const int *input);
void write_grid(int **solution, const int dim);

int *read_input16(const char *input)
{
    unsigned int i_input;
    unsigned int i_array;
    int *arr;

    i_input = 0;
    i_array = 0;
    arr = malloc(16 * sizeof(int));
    if (arr == NULL)
    {
        write(1, "memory allocation not successful.\n", 34);
        return NULL;
    }
    while (input[i_input] != '\0')
    {
        if (input[i_input] >= '0' && input[i_input] <= '4' && i_array <= 15)
        {
            arr[i_array] = input[i_input] - '0';
            i_array++;
        }
        else if (input[i_input] != ' ' || i_array > 15)
            return (NULL);
        i_input++;
    }
    return arr;
}

int **get_grid44(const int *input)
{
    int **solution; // this is meant to be an 4x4 array (two dimentions)
    // int *col1 = {input[0], input[4]};
    // int *col2 = {input[1], input[5]};
    // int *col3 = {input[2], input[6]};

    solution = malloc(4 * sizeof(int *)); // 4 pointers of rows
    int r = 0;
    while (r <= 3)
    {
        solution[r] = malloc(4 * sizeof(int)); // a row of 4 integers
        r++;
    }

    _core_solver44(input, solution);

    return solution;
}

void write_grid(int **solution, const int dim)
{
    int row;
    int col;
    char buf;

    row = 0;
    while (row <= dim - 1)
    {
        col = 0;
        while (col <= dim - 1)
        {
            if (col < dim - 1 && solution[row][col] >= 1 && solution[row][col] <= 9)
            {
                buf = solution[row][col] + '0';
                write(1, &buf, 1);
                write(1, " ", 1);
            }
            else if (col == dim - 1 && solution[row][col] >= 1 && solution[row][col] <= 9)
            {
                buf = solution[row][col] + '0';
                write(1, &buf, 1);
                write(1, "\n", 1);
            }
            col++;
        }
        row++;
    }
}

// int main(int argc, char *argv[])
// {
int main(void)
{
    int argc = 2;
    char *argv[] = {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"};
    int **solution;
    int *input;

    input = read_input16(argv[1]);
    if (argc != 2 || input == NULL)
    {
        write(1, "Error\n", 6);
        return (-1);
    }

    int line1[] = {1, 2, 4, 4};
    bool vali = _validate_line(4, 1, line1, 4);

    solution = get_grid44(input);
    write_grid(solution, 4);
    return (0);
}