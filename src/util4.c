#include <stdlib.h>
#include <stdio.h>
#include "core.h"

int **_init_solution(int dim);
int *read_input16(const char *input);
int **get_grid44(const int *input, int **all_combo, int *flag);

// Create a solution matrix with desire dimention
// Values are initialized with zeros;
int **_init_solution(int dim)
{
	int **solution;

	solution = malloc(dim * sizeof(int *));
	return (solution);
}

int *read_input16(const char *input)
{
	int i_input;
	int i_array;
	int *arr;

	i_input = -1;
	i_array = 0;
	arr = malloc(16 * sizeof(int));
	while (input[++i_input] != '\0')
	{
		if (input[i_input] >= '0' && input[i_input] <= '4' && i_array <= 15)
		{
			arr[i_array] = input[i_input] - '0';
			i_array++;
		}
		else if (input[i_input] != ' ' || i_array > 15)
		{
			printf("invalid input\n");
			return (NULL);
		}
	}
	if (i_array != 16)
	{
		printf("input count not 16\n");
		return (NULL);
	}
	return (arr);
}

int **get_grid44(const int *input, int **all_combo, int *flag)
{
	int **solution;

	solution = _init_solution(4);
	_core_solver44(input, solution, all_combo, flag);
	return (solution);
}
