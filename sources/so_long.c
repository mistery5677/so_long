/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:49:03 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 22:49:04 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_objects(t_data *data)
{
	data->wall_flag = 0;
	data->back_flag = 0;
	data->player_flag = 0;
	data->collect_flag = 0;
	data->exit_flag = 0;
	data->exit_flag2 = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1 && argc < 3)
	{
		read_map(&data, argv[1]);
		init_objects(&data);
		if (check_map(&data, argv[1]) == 0)
		{
			init_game(&data);
			gameplay(&data);
			mlx_loop(data.mlx);
		}
		else
			free_map(data.map);
	}
}
