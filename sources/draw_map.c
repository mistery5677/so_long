/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:56:35 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/15 22:50:44 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * 32, y * 32);
}

int	map_draw(t_data *data, t_map *map, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == '1')
				img_draw(data, img->wall, x, y);
			else if (map->matrix[y][x] == '0')
				img_draw(data, img->back, x, y);
			else if (map->matrix[y][x] == 'P')
				img_draw(data, img->player, x, y);
			else if (map->matrix[y][x] == 'C')
				img_draw(data, img->collect, x, y);
			else if (map->matrix[y][x] == 'E')
				img_draw(data, img->exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
