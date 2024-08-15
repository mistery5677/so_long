/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:49:03 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/15 22:50:31 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_objects(t_data *data)
{
	int i;

	i = 0;
	data->wall_flag = 0;
	data->back_flag = 0;
	data->player_flag = 0;
	data->collect_flag = 0;
	data->exit_flag = 0;
	data->exit_flag2 = 0;
	while(data->map[i])
		i++;
	data->height = i;
	data->width = ft_strlen(data->map[0]);
}

static int check_name(char *path)
{
	int i;

	i = 0;
	while(path[i] && path[i] != '.')
		i++;
	if(path[i] == '\0' || ft_strncmp(path + i, ".ber", 4) != 0)
	{
		return 1;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && check_name(argv[1]) == 0)
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
	else
		ft_putstr_fd("Error\n", 2);
}
