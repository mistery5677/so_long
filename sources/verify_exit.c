/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:21:43 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 22:53:23 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	finish(t_map *map)
{
	int	y;
	int	x;
	int	exit;

	exit = 0;
	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'E')
				exit = 1;
			x++;
		}
		y++;
	}
	if (exit == 0)
		return (0);
	return (1);
}

static int	find_collects(t_map *map)
{
	int	y;
	int	x;
	int	collects;

	collects = 0;
	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'C')
				collects++;
			x++;
		}
		y++;
	}
	return (collects);
}

void	find_player(t_map *map, t_player_info *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	print_exit(t_data *data, t_map *map, t_flags *flags)
{
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y] && flags->exit2 == 0)
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'E')
			{
				mlx_destroy_image(data->mlx, data->img.exit);
				data->img.exit = mlx_xpm_file_to_image(data->mlx,
						"./assets/exit2.xpm", &map->width, &map->height);
				flags->exit2 = 1;
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x
					* 32, y * 32);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	verify(int key_released, t_data *data)
{
	(void)key_released;
	if (find_collects(&data->map) == 0)
		print_exit(data, &data->map, &data->flags);
	if (finish(&data->map) == 0 && data->flags.exit2 == 1)
		close_game(data);
	return (0);
}
