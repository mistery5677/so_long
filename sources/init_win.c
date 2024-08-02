#include "so_long.h"

void init_win(t_win *map)
{
        map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, LENGTH, HEIGHT, "Hello world!");
}

//My put pixel function because the original one is much slower
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
}