#include <stdlib.h>
#include <stdio.h>
#include "core.h"

int *read_input16(const char *input);
int **get_grid44(const int *input, int **all_combo, int *flag);

int *read_input16(const char *input)
{
	int i_input = -1;
	int i_array = 0;
	int *arr = malloc(16 * sizeof(int));

	while (input[++i_input] != '\0')
	{
		if (input[i_input] >= '1' && input[i_input] <= '4' && i_array <= 15)
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
		printf("input has more or less than 16 numbers\n");
		return (NULL);
	}
	return (arr);
}

int **get_grid44(const int *input, int **all_combo, int *flag)
{
	int **solution = malloc(4 * sizeof(int *));

	_core_solver44(input, solution, all_combo, flag);
	return (solution);
}
