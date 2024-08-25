/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:49:39 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/25 22:14:18 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_exit(t_data *data, int x, int y)
{
	char	*number;

	mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 1 * 32, 0
		* 32);
	mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 2 * 32, 0
		* 32);
	if (data->map.matrix[y][x] == 'E')
		data->flags.exit = 0;
	else
		data->flags.exit = 1;
	data->moves++;
	number = ft_itoa(data->moves);
	ft_printf("Moves %d\n", data->moves);
	mlx_string_put(data->mlx, data->win, 33, 15, 1000000, "es:");
	mlx_string_put(data->mlx, data->win, 50, 15, 1000000, number);
	free(number);
}

void	change_img(t_data *data, char *path)
{
	mlx_destroy_image(data->mlx, data->img.player);
	data->img.player = mlx_xpm_file_to_image(data->mlx, path, &data->map.width,
			&data->map.height);
}
