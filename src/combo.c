#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

void get_all_combo24(int **line_collection);
void free_combo(int **combo);

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
                    if (_check_unique(i, 4))
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
