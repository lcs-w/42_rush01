#include <stdlib.h>

int *_copy_column(int **solution, int col, int dim);
void _assign_solution_rows(int **solution, int **all_combo,
						   int *row, int dim);
bool _check_unique(const int *arr, int dim);
int _check_appearance(const int *line, int dim);
int *_make_one_line(int *i, int dim);

void _assign_solution_rows(int **solution, int **all_combo,
						   int *row, int dim)
{
	int i = -1;

	while (++i < dim)
		solution[i] = all_combo[row[i]];
}

int *_copy_column(int **solution, int col, int dim)
{
	int r = 0;
	int *col_copy = malloc(dim * sizeof(int));

	while (r < dim)
	{
		col_copy[r] = solution[r][col];
		r++;
	}
	return (col_copy);
}

bool _check_unique(const int *arr, int dim)
{
	int i = -1;
	int j;

	while (++i < dim)
	{
		j = i;
		while (++j < dim)
		{
			if (arr[i] == arr[j])
				return (false);
		}
	}
	return (true);
}

int _check_appearance(const int *line, int dim)
{
	int i = -1;
	bool *target;

	target = malloc((size_t)dim * sizeof(bool));
	while (++i < dim)
		target[i] = false;
	i = -1;
	while (++i < dim)
	{
		if (!target[line[i]])
			target[line[i]] = true;
		else
		{
			free(target);
			return (false);
		}
	}
	free(target);
	return (true);
}

int *_make_one_line(int *i, int dim)
{
	int *line;

	line = malloc((size_t)dim * sizeof(int));
	while (--dim >= 0)
	{
		line[dim] = i[dim];
	}
	return (line);
}
