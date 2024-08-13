/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:56:35 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 18:56:36 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * 32, y * 32);
}

int	map_draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				img_draw(data, data->wall, x, y);
			else if (data->map[y][x] == '0')
				img_draw(data, data->back, x, y);
			else if (data->map[y][x] == 'P')
				img_draw(data, data->player, x, y);
			else if (data->map[y][x] == 'C')
				img_draw(data, data->collect, x, y);
			else if (data->map[y][x] == 'E')
				img_draw(data, data->exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
