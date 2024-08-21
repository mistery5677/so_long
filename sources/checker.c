/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:50:25 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/13 18:56:01 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(t_data *data)
{
	int				i;
	unsigned int	len;

	len = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

static int	check_border(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y][x] == '1')
		x++;
	if (data->map[y][x] != '1' && data->map[y][x] != '\0')
		return (1);
	y++;
	while (data->map[y + 1] != NULL)
	{
		if (data->map[y][0] != '1')
			return (1);
		if (data->map[y][data->width - 1] != '1')
			return (1);
		y++;
	}
	x = 0;
	while (data->map[y][x] == '1')
		x++;
	if (data->map[y][x] != '1' && data->map[y][x] != '\0')
		return (1);
	return (0);
}

static void	check_objects(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				data->wall_flag++;
			else if (data->map[y][x] == '0')
				data->back_flag++;
			else if (data->map[y][x] == 'C')
				data->collect_flag++;
			else if (data->map[y][x] == 'P')
				data->player_flag++;
			else if (data->map[y][x] == 'E')
				data->exit_flag++;
			x++;
		}
		y++;
	}
}

static void	flood_map(t_data *data, int x, int y)
{
	if (y < 0 || y > data->height || x < 0 || x > data->width
		|| data->map[y][x] == '1' || data->map[y][x] == '2')
		return ;
	else
	{
		data->map[y][x] = '2';
		flood_map(data, x, y - 1);
		flood_map(data, x, y + 1);
		flood_map(data, x + 1, y);
		flood_map(data, x - 1, y);
	}
}

void print_map(char **map)
{
	int i = 0;
	int j = 0;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static int pre_gameplay(t_data *data, char *path)
{
	find_player(data, &data->player_struct);
	flood_map(data, data->player_struct.player_x, data->player_struct.player_y);
	check_objects(data);
	if (data->exit_flag == 1 || data->collect_flag == 1)
		return -1;
	free_map(data->map);
	read_map(data, path);
	return 0;
}

int	check_map(t_data *data, char *path)
{
	if (pre_gameplay(data, path) == -1)
		return -1;
	print_map(data->map);
	check_objects(data);
	if (data->wall_flag < 1 || data->collect_flag < 1
		|| data->player_flag != 1 || data->exit_flag != 1)
		return (-1);
	else if (check_rectangle(data) == 1)
		return (-1);
	else if (check_border(data) == 1)
		return (-1);
	return (0);
}
