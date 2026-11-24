#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "combo.h"
#include "util.h"
#include "output.h"

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
