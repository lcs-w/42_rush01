#include <stdlib.h>

int *_copy_column(int **solution, int col, int dim);
void _assign_solution_rows4(int **solution, int **all_combo,
							int *row, int dim);

void _assign_solution_rows4(int **solution, int **all_combo,
							int *row, int dim)
{
	int i;

	i = -1;
	while (++i < dim)
	{
		solution[i] = all_combo[row[i]];
	}
}

int *_copy_column(int **solution, int col, int dim)
{
	int r;
	int *col_copy;

	r = 0;
	col_copy = malloc(dim * sizeof(int));
	while (r < dim)
	{
		col_copy[r] = solution[r][col];
		r++;
	}
	return (col_copy);
}
