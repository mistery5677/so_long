#include "so_long.h"

static int finish(t_data *data)
{
        int y;
        int x;
        int exit;

        exit = 0;
        y = 0;
        while(data->map[y])
        {
                x = 0;
                while(data->map[y][x])
                {
                        if(data->map[y][x] == 'E')
                                exit = 1;
                        x++;
                }
                y++;
        }
        if(exit == 0)
                return 0;
        return 1;
}

static int find_collects(t_data *data)
{
        int y;
        int x;
        int collects;

        collects = 0;
        y = 0;
        while(data->map[y])
        {
                x = 0;
                while(data->map[y][x])
                {
                        if(data->map[y][x] == 'C')
                                collects++;
                        x++;
                }
                y++;
        }
        return collects;
}

static void print_exit(t_data *data)
{
        int y;
        int x;

        y = 0;
        mlx_destroy_image(data->mlx, data->exit);
        data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/exit2.xpm", &data->width, &data->height);
        while(data->map[y] && data->exit_flag2 == 0)
        {
                x = 0;
                while(data->map[y][x])
                {
                        if(data->map[y][x] == 'E')
                        {
                                data->exit_flag2 = 1;
                                mlx_put_image_to_window(data->mlx, data->win, data->exit, x * 32, y * 32);
                                return;
                        }
                        x++;
                }
                y++;
        }
}

static int verify(int key_released, t_data *data)
{
        (void)key_released;
        if(find_collects(data) == 0)
                print_exit(data);
        if(finish(data) == 0 && data->exit_flag2 == 1)
                close_game(data);
        return 0;
}

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
        mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
        mlx_hook(data->win, KeyRelease, KeyReleaseMask, verify, data);
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