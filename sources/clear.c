#include "so_long.h"

void free_map(char **map)
{
        int i;

        i = 0;
        while(map[i])
        {
                free(map[i]);
                i++;
        }
        free(map);
}

int close_game(t_data *data)
{
        free_map(data->map);
        mlx_destroy_image(data->mlx, data->back);
        mlx_destroy_image(data->mlx, data->wall);
        mlx_destroy_image(data->mlx, data->collect);
        mlx_destroy_image(data->mlx, data->exit);
        mlx_destroy_image(data->mlx, data->player);
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(0);
        return 0;
}