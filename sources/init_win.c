/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:13:11 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/25 19:02:31 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_data *data, t_map *map, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(data->mlx, TREE, &map->height,
			&map->width);
	img->back = mlx_xpm_file_to_image(data->mlx, GRASS, &map->height,
			&map->width);
	img->player = mlx_xpm_file_to_image(data->mlx, DOG_RIGHT, &map->height,
			&map->width);
	img->collect = mlx_xpm_file_to_image(data->mlx, BONE, &map->height,
			&map->width);
	img->exit = mlx_xpm_file_to_image(data->mlx, HOUSE, &map->height,
			&map->width);
}

static void	error_screen(t_data *data)
{
	ft_putstr_fd("Map to big\n", 2);
	free_map(data->map.matrix);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &data->screen_h, &data->screen_w);
	if (data->screen_h < data->map.height
		|| data->screen_w < data->map.width + 32)
		error_screen(data);
	data->flags.player = 2;
	data->win = mlx_new_window(data->mlx, data->map.height, data->map.width,
			"So_long");
	mlx_string_put((*data).mlx, (*data).win, 10, 10, 1000000, "moves");
	load_img(data, &data->map, &data->img);
	map_draw(data, &data->map, &data->img);
}
