/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:49:39 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/23 22:49:40 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_exit(t_data *data, int x, int y)
{
	if (data->map.matrix[y][x] == 'E')
		data->flags.exit = 0;
	else
		data->flags.exit = 1;
	data->moves++;
	ft_printf("Moves %d\n", data->moves);
}

void	change_img(t_data *data, char *path)
{
	mlx_destroy_image(data->mlx, data->img.player);
	data->img.player = mlx_xpm_file_to_image(data->mlx, path, &data->map.width,
			&data->map.height);
}
