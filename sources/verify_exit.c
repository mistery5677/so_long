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

static int	finish(t_data *data)
{
	int	y;
	int	x;
	int	exit;

	exit = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				exit = 1;
			x++;
		}
		y++;
	}
	if (exit == 0)
		return (0);
	return (1);
}

static int	find_collects(t_data *data)
{
	int	y;
	int	x;
	int	collects;

	collects = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				collects++;
			x++;
		}
		y++;
	}
	return (collects);
}

void	find_player(t_data *data, t_player_struct *player_struct)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				player_struct->player_x = x;
				player_struct->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	print_exit(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y] && data->exit_flag2 == 0)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				mlx_destroy_image(data->mlx, data->exit);
				data->exit = mlx_xpm_file_to_image(data->mlx,
						"./assets/exit2.xpm", &data->width, &data->height);
				data->exit_flag2 = 1;
				mlx_put_image_to_window(data->mlx, data->win, data->exit, x
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
	if (find_collects(data) == 0)
		print_exit(data);
	if (finish(data) == 0 && data->exit_flag2 == 1)
		close_game(data);
	return (0);
}
