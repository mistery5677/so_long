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

static void	init_flags(t_flags *flags, t_data *data)
{
	flags->wall = 0;
	flags->back = 0;
	flags->player = 0;
	flags->collect = 0;
	flags->exit = 0;
	flags->exit2 = 0;
	data->moves = 0;
	ft_printf("Moves %d\n", data->moves);
}

static int check_name(char *path)
{
	int i;

	i = 0;
	while(path[i] && path[i] != '.')
		i++;
	if(path[i] == '\0' || ft_strncmp(path + i, ".ber", 4) != 0)
		return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_name(argv[1]))
		return ft_putstr_fd("Error\n", 2), 0;
	read_map(&data.map, argv[1]);
	init_flags(&data.flags, &data);
	if (check_map(&data, &data.flags, argv[1]) != 0)
		return free_map(data.map.matrix), ft_putstr_fd("Error\n", 2), 0;
	init_game(&data);
	gameplay(&data);
	mlx_loop(data.mlx);
}
