/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:13:55 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/15 18:56:19 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map, char *path)
{
	int		fd;
	char	*backup;
	char	*str;
	int i;

	i = 0;
	backup = ft_strdup("");
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		backup = ft_strjoin_gnl(backup, str);
		free(str);
		str = get_next_line(fd);
	}
	map->matrix = ft_split(backup, '\n');
	while(map->matrix[i])
		i++;
	map->height = i;
	map->width = ft_strlen(map->matrix[0]);
	free(backup);
	free(str);
	close(fd);
}
