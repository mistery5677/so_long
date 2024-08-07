#include "so_long.h"

static void load_img(t_data *data)
{
        data->wall = mlx_xpm_file_to_image(data->mlx, "./assets/bush.xpm", &data->width, &data->height);
        data->back = mlx_xpm_file_to_image(data->mlx, "./assets/grass.xpm", &data->width, &data->height);
        data->player = mlx_xpm_file_to_image(data->mlx, "./assets/dog.xpm", &data->width, &data->height);
        data->collect = mlx_xpm_file_to_image(data->mlx, "./assets/bone.xpm", &data->width, &data->height);
        data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", &data->width, &data->height);
}

static void window_size_init(t_data *data)
{
        int i;

        i = 0;
        data->width = ft_strlen(data->map[0]) * 32;
        while(data->map[i])
                i++;
        data->height = i * 32;
}

void init_game(t_data *data)
{
        data->mlx = mlx_init();
	window_size_init(data);
        data->win = mlx_new_window(data->mlx, data->width, data->height, "So_long");
        load_img(data);
        map_draw(data);
}

//My put pixel function because the original one is much slower                            |
/* void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
} */