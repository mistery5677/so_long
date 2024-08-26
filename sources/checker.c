/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:50:25 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/25 21:34:35 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(t_map *map)
{
	int				i;
	unsigned int	len;

	len = ft_strlen(map->matrix[0]);
	i = 0;
	while (map->matrix[i])
	{
		if (ft_strlen(map->matrix[i]) != len)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_border(t_map *map)
{
	int	y;

	y = 0;
	if (check_row(map->matrix[y], '1') == -1)
		return (-1);
	y++;
	while (map->matrix[y + 1] != NULL)
	{
		if (map->matrix[y][(map->height / 32) - 1] != '1'
		|| map->matrix[y][0] != '1')
			return (-1);
		y++;
	}
	if (check_row(map->matrix[y], '1') == -1)
		return (-1);
	return (0);
}

static void	check_objects(t_flags *flags, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == '1' && flags->errors != -1)
				flags->wall++;
			else if (map->matrix[y][x] == '0')
				flags->back++;
			else if (map->matrix[y][x] == 'C')
				flags->collect++;
			else if (map->matrix[y][x] == 'P')
				flags->player++;
			else if (map->matrix[y][x] == 'E')
				flags->exit++;
			else if (map->matrix[y][x] != '\0')
				flags->errors = -1;
			x++;
		}
		y++;
	}
}

static int	pre_gameplay(t_data *data, t_flags *flags, char *path)
{
	init_flags(flags, data);
	find_player(&data->map, &data->player_info);
	flood_map(&data->map, data->player_info.x, data->player_info.y);
	check_objects(flags, &data->map);
	if (flags->exit == 1 || flags->collect == 1)
		return (-1);
	free_map(data->map.matrix);
	read_map(&data->map, path);
	return (0);
}

int	check_map(t_data *data, t_flags *flags, char *path)
{
	check_objects(flags, &data->map);
	if (flags->collect < 1 || flags->player != 1 || flags->exit != 1
		|| flags->errors == -1)
		return (-1);
	else if (check_rectangle(&data->map) == -1)
		return (-1);
	else if (check_border(&data->map) == -1)
		return (-1);
	else if (pre_gameplay(data, flags, path) == -1)
		return (-1);
	flags->exit = 1;
	return (0);
}
