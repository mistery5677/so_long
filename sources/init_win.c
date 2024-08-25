/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:13:11 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/23 22:48:27 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_data *data, t_map *map, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(data->mlx, TREE, &map->width,
			&map->height);
	img->back = mlx_xpm_file_to_image(data->mlx, GRASS, &map->width,
			&map->height);
	img->player = mlx_xpm_file_to_image(data->mlx, DOG_RIGHT, &map->width,
			&map->height);
	img->collect = mlx_xpm_file_to_image(data->mlx, BONE, &map->width,
			&map->height);
	img->exit = mlx_xpm_file_to_image(data->mlx, HOUSE, &map->width,
			&map->height);
}

static void	window_size_init(t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map->matrix[0]) * 32;
	while (map->matrix[i])
		i++;
	map->height = i * 32;
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	window_size_init(&data->map);
	data->flags.player = 2;
	data->win = mlx_new_window(data->mlx, data->map.width, data->map.height,
			"So_long");
	load_img(data, &data->map, &data->img);
	map_draw(data, &data->map, &data->img);
}
