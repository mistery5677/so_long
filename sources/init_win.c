/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:13:11 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 20:13:18 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "./assets/bush.xpm",
			&data->width, &data->height);
	data->back = mlx_xpm_file_to_image(data->mlx, "./assets/grass.xpm",
			&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./assets/dog.xpm",
			&data->width, &data->height);
	data->collect = mlx_xpm_file_to_image(data->mlx, "./assets/bone.xpm",
			&data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm",
			&data->width, &data->height);
}

static void	window_size_init(t_data *data)
{
	int	i;

	i = 0;
	data->width = ft_strlen(data->map[0]) * 32;
	printf("width %d\n", data->width);
	while (data->map[i])
		i++;
	data->height = i * 32;
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	window_size_init(data);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "So_long");
	load_img(data);
	map_draw(data);
}
