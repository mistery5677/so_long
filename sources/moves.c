/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:14:24 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 20:16:23 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verify_move(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1' || x < 0 || y < 0)
		return (1);
	return (0);
}

void	move_right(t_data *data, int x, int y)
{
	if (verify_move(data, x + 1, y) == 0)
	{
		if (data->map[y][x + 1] == 'E')
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
			data->exit_flag = 0;
		}
		else if (data->exit_flag == 0)
		{
			data->map[y][x] = 'E';
			img_draw(data, data->exit, x, y);
			data->exit_flag = 1;
		}
		else
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
		}
		x++;
		data->map[y][x] = 'P';
		img_draw(data, data->player, x, y);
	}
	return ;
}

void	move_left(t_data *data, int x, int y)
{
	if (verify_move(data, x - 1, y) == 0)
	{
		if (data->map[y][x - 1] == 'E')
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
			data->exit_flag = 0;
		}
		else if (data->exit_flag == 0)
		{
			data->map[y][x] = 'E';
			img_draw(data, data->exit, x, y);
			data->exit_flag = 1;
		}
		else
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
		}
		x--;
		data->map[y][x] = 'P';
		img_draw(data, data->player, x, y);
	}
	return ;
}

void	move_up(t_data *data, int x, int y)
{
	if (verify_move(data, x, y - 1) == 0)
	{
		if (data->map[y - 1][x] == 'E')
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
			data->exit_flag = 0;
		}
		else if (data->exit_flag == 0)
		{
			data->map[y][x] = 'E';
			img_draw(data, data->exit, x, y);
			data->exit_flag = 1;
		}
		else
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
		}
		y--;
		data->map[y][x] = 'P';
		img_draw(data, data->player, x, y);
	}
	return ;
}

void	move_down(t_data *data, int x, int y)
{
	if (verify_move(data, x, y + 1) == 0)
	{
		if (data->map[y + 1][x] == 'E')
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
			data->exit_flag = 0;
		}
		else if (data->exit_flag == 0)
		{
			data->map[y][x] = 'E';
			img_draw(data, data->exit, x, y);
			data->exit_flag = 1;
		}
		else
		{
			data->map[y][x] = '0';
			img_draw(data, data->back, x, y);
		}
		y++;
		data->map[y][x] = 'P';
		img_draw(data, data->player, x, y);
	}
	return ;
}
