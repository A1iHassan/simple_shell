#include "shell.h"

/**
 * free_grid - frees previously created array
 * @grid: array's pointer
 * @height: array's height
 */
void _free(char **grid, int height)
{
  int i = 0;

  for (i = 0; i < height; i++)
    {
      free(grid[i]); }
  free(grid);
}