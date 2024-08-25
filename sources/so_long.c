/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:49:03 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/25 22:37:30 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_name(char *path)
{
	int	i;

	i = 0;
	while (path[i] && path[i] != '.')
		i++;
	if (path[i] == '\0' || ft_strncmp(path + i, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_name(argv[1]))
		return (ft_putstr_fd("Error\n", 2), 0);
	read_map(&data.map, argv[1]);
	init_flags(&data.flags, &data);
	ft_printf("Moves %d\n", data.moves);
	if (check_map(&data, &data.flags, argv[1]) != 0)
		return (free_map(data.map.matrix), ft_putstr_fd("Error\n", 2), 0);
	init_game(&data);
	gameplay(&data);
	mlx_string_put(data.mlx, data.win, 15, 15, 1000000, "Moves:0");
	mlx_loop(data.mlx);
}
