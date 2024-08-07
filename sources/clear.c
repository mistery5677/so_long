#include "so_long.h"

void free_map(t_data *data)
{
        int i;

        i = 0;
        while(data->map[i])
        {
                free(data->map[i]);
                i++;
        }
        free(data->map);
}

int close_game(t_data *data)
{
        free_map(data);
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