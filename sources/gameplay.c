#include "so_long.h"

static int key_press(int key_pressed, t_data *data)
{
        (void)key_pressed;
        (void)data;
        return 0;
}

void gameplay(t_data *data)
{
        mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
        mlx_hook(data->mlx_win, 9, 1L << 21, map_draw, data);
}