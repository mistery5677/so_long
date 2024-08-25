/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:56:50 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/25 19:06:31 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_press(int key_pressed, t_data *data)
{
	int	x;
	int	y;

	find_player(&data->map, &data->player_info);
	y = data->player_info.y;
	x = data->player_info.x;
	if (key_pressed == ESC || data->moves < 0)
		close_game(data);
	else if (key_pressed == RIGHT || key_pressed == RIGHT_ARROW)
		move_right(data, &data->img, x, y);
	else if (key_pressed == LEFT || key_pressed == LEFT_ARROW)
		move_left(data, &data->img, x, y);
	else if (key_pressed == UP || key_pressed == UP_ARROW)
		move_up(data, &data->img, x, y);
	else if (key_pressed == DOWN || key_pressed == DOWN_ARROW)
		move_down(data, &data->img, x, y);
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, verify, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_game, data);
}
