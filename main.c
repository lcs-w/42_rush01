#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "combo.h"
#include "util.h"

void write_digit(int digit, char *c);
void write_grid(int **solution, const int dim);
void free_solution(int **solution, int dim);

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

int **solve44(int *input, int **all_combo, int *flag)
{
	int **solution;

	all_combo = malloc(25 * sizeof(int *));
	get_all_combo24(all_combo);
	solution = get_grid44(input, all_combo, flag);
	return (solution);
}
// int	main(void)
// {
// 	int		argc = 2;
// 	char	*argv[] = {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"};
int main(int argc, char *argv[])
{
	int **solution;
	int *input;
	int dim;
	int flag;

	dim = 4;
	flag = -1;
	if (argc != 2)
	{
		printf("input error\n");
		return (-1);
	}
	input = read_input16(argv[1]);
	if (input == NULL)
		return (-1);
	int **all_combo = malloc(dim * sizeof(int *));
	if (dim == 4)
		solution = solve44(input, all_combo, &flag);
	if (flag == 1)
		write_grid(solution, dim);
	else
		write(1, "program ended\n", 6);
	free(input);
	free(solution);
	free_combo(all_combo);
	return (0);
}
