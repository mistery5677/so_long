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

void	move_right(t_data *data, t_img *img, int x, int y)
{
	if (data->map.matrix[y][x + 1] == '1')
		return ;
	
	if (data->flags.exit == 0)
	{
		data->map.matrix[y][x] = 'E';
		img_draw(data, img->exit, x, y);
	}
	else
	{
		data->map.matrix[y][x] = '0';
		img_draw(data, img->back, x, y);
	}
	x++;
	verify_exit (data, x, y);
	if(data->flags.player == 3)
		change_img(data, DOG_RIGHT);
	data->flags.player = 2;
	data->map.matrix[y][x] = 'P';
	img_draw (data, img->player, x, y);
}

void	move_left(t_data *data, t_img *img, int x, int y)
{
	if (data->map.matrix[y][x - 1] == '1')
		return ;
	if (data->flags.exit == 0)
	{
		data->map.matrix[y][x] = 'E';
		img_draw(data, img->exit, x, y);
	}
	else
	{
		data->map.matrix[y][x] = '0';
		img_draw(data, img->back, x, y);
	}
	x--;
	verify_exit (data, x, y);
	if(data->flags.player == 2)
		change_img(data, DOG_LEFT);
	data->flags.player = 3;
	data->map.matrix[y][x] = 'P';
	img_draw (data, img->player, x, y);
}

void	move_up(t_data *data, t_img *img, int x, int y)
{
	if (data->map.matrix[y - 1][x] == '1')
		return ;
	if (data->flags.exit == 0)
	{
		data->map.matrix[y][x] = 'E';
		img_draw(data, img->exit, x, y);
	}
	else
	{
		data->map.matrix[y][x] = '0';
		img_draw(data, img->back, x, y);
	}
	y--;
	verify_exit (data, x, y);
	data->map.matrix[y][x] = 'P';
	img_draw (data, img->player, x, y);
}

void	move_down(t_data *data, t_img *img, int x, int y)
{
	if (data->map.matrix[y + 1][x] == '1')
		return ;
	if (data->flags.exit == 0)
	{
		data->map.matrix[y][x] = 'E';
		img_draw(data, img->exit, x, y);
	}
	else
	{
		data->map.matrix[y][x] = '0';
		img_draw(data, img->back, x, y);
	}
	y++;
	verify_exit (data, x, y);
	data->map.matrix[y][x] = 'P';
	img_draw (data, img->player, x, y);
}
