#include <stdlib.h>
#include <stdbool.h>

int *_make_one_line(int *i, int dim);
int _check_mutex(int *i);
void get_all_combo24(int **line_collection);
void free_combo(int **combo);
int _check_appearance(const int *line, int dim);

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

int _check_unique(int *i)
{
    return (i[1] != i[0] && i[2] != i[1] && i[2] != i[0] && i[3] != i[2] && i[3] != i[1] && i[3] != i[0]);
}

// line_collection should have a size of 24
void get_all_combo24(int **line_collection)
{
    int i[4];
    int count;

    count = -1;
    i[0] = 0;
    while (++i[0] < 5)
    {
        i[1] = 0;
        while (++i[1] < 5)
        {
            i[2] = 0;
            while (++i[2] < 5)
            {
                i[3] = 0;
                while (++i[3] < 5)
                {
                    if (_check_unique(i))
                        line_collection[++count] = _make_one_line(i, 4);
                }
            }
        }
    }
    line_collection[++count] = NULL;
}

void free_combo(int **combo)
{
    int count;

    if (!combo)
        return;
    count = 0;
    while (combo[count])
    {
        free(combo[count]);
        count++;
    }
    free(combo);
}

int _check_appearance(const int *line, int dim)
{
    int i = -1;
    bool *target;

    target = malloc((size_t)dim * sizeof(bool));
    while (++i < dim)
    {
        target[i] = false;
    }
    while (--i >= 0)
    {
        if (!target[line[i]])
            target[line[i]] = true;
        else
        {
            free(target);
            return (0);
        }
    }
    free(target);
    return (1);
}
