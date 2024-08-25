#include "so_long.h"

void	flood_map(t_map *map, int x, int y)
{
	if (y < 0 || y > map->height || x < 0 || x > map->width
		|| map->matrix[y][x] == '1' || map->matrix[y][x] == '2')
		return ;
	else
	{
		map->matrix[y][x] = '2';
		flood_map(map, x, y - 1);
		flood_map(map, x, y + 1);
		flood_map(map, x + 1, y);
		flood_map(map, x - 1, y);
	}
}

void	init_flags(t_flags *flags, t_data *data)
{
	flags->wall = 0;
	flags->back = 0;
	flags->player = 0;
	flags->collect = 0;
	flags->exit = 0;
	flags->exit2 = 0;
	data->moves = 0;
}

int     check_row(char *row, char wall)
{
        int i;

        i = 0;
        while(row[i] && row[i] == wall)
                i++;
        if (row[i] != wall && row[i])
                return -1;
        return 0;
}