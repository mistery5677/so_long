#include "so_long.h"

static int key_press(int key_pressed, t_data *data)
{
        int x;
        int y;

        y = 0;
        x = 0;
        while(data->map[y] && data->map[y][x] != 'P')
        {
                x = 0;
                while(data->map[y][x] && data->map[y][x] != 'P')
                        x++;
                if(data->map[y][x] != 'P')
                        y++;
        }
        printf("key pressed %d \n", key_pressed);
        if(key_pressed == 100 || key_pressed == 65363)
                move_right(data, x, y);
        else if(key_pressed == 97 || key_pressed == 65361)
                move_left(data, x, y);
        else if(key_pressed == 119 || key_pressed == 65362)
                move_up(data, x, y);
        else if(key_pressed == 115 || key_pressed == 65364)
                move_down(data, x, y);
        else if(key_pressed == 65307)
                close_game(data);
        return 0;
}

void gameplay(t_data *data)
{
        mlx_hook(data->win, 2, 1L << 0, key_press, data);
        mlx_hook(data->win, 17, 1L << 17, close_game, data);
        mlx_hook(data->win, 9, 1L << 21, map_draw, data);
}

/* D = 100
A = 97
W = 119
S = 115

LEFT = 65361
UP = 65362
RIGHT = 65363
DOWN = 65364 */