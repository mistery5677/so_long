#include "so_long.h"

static int check_rectangle(t_data *data)
{
        int i;
        unsigned int len;

        len = ft_strlen(data->map[0]);
        i = 0;
        while(data->map[i])
        {
                if (ft_strlen(data->map[i]) != len)
                        return 1;
                i++;
        }
        return 0;
}

static int check_border(t_data *data)
{
        int     y;
        int     x;

        y = 0;
        x = 0;
        while(data->map[y][x] == '1')
                x++;
        if(data->map[y][x] != '1' && data->map[y][x] != '\0')
                return 1;
        y++;
        while(data->map[y + 1] != NULL)
        {
                if(data->map[y][0] != '1')
                        return 1;
                if(data->map[y][data->width - 1] != '1')
                        return 1;
                y++;
        }
        x = 0;
        while(data->map[y][x] == '1')
                x++;
        if(data->map[y][x] != '1' && data->map[y][x] != '\0')
                return 1;
        return 0;
}

static void init_objects(t_data *data)
{
        data->wall_flag = 0;
        data->back_flag = 0;
        data->player_flag = 0;
        data->collect_flag = 0;
        data->exit_flag = 0;
        data->exit_flag2 = 0;
}

static void check_objects(t_data *data)
{
        int y;
        int x;

        y = 0;
        init_objects(data);
        while(data->map[y])
        {
                x = 0;
                while(data->map[y][x])
                {
                        if(data->map[y][x] == '1')
                                data->wall_flag = 1;
                        else if(data->map[y][x] == '0')
                                data->back_flag = 1;
                        else if(data->map[y][x] == 'C')
                                data->collect_flag = 1;
                        else if(data->map[y][x] == 'P')
                                data->player_flag = 1;
                        else if(data->map[y][x] == 'E')
                                data->exit_flag = 1;
                        x++;
                }
                y++;
        }
}

static int size_lines(char **map)
{
        int x;
        
        x = 0;
        while(map[x])
                x++;
        return x;
}

static void find_player(t_data *data)
{
        int x;
        int y;

        y = 0;
        while(data->map[y])
        {
                x = 0;
                while(data->map[y][x])
                {
                        if(data->map[y][x] == 'P')
                        {
                                data->player_x = x;
                                data->player_y = y;
                                return ;
                        }
                        x++;
                }
                y++;
        }
}

/* static void print_map(char **map)
{
        int i;

        i = 0;
        while(map[i])
        {
                printf("%s\n", map[i]);
                i++;
        }
} */

static void flood_map(t_data *data, int x, int y)
{
        int collumns;
        int lines;

        lines = size_lines(data->map);
        collumns = ft_strlen(data->map[0]);
        if(y < 0 || y > lines || x < 0 || x > collumns || data->map[y][x] == '1' || data->map[y][x] == '2')
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

int check_map(t_data* data, char *path)
{
        find_player(data);
        flood_map(data, data->player_x, data->player_y);
        check_objects(data);
        if(data->exit_flag >= 1 || data->collect_flag >= 1)
                return 1;
        free_map(data->map);
        read_map(data, path);
        check_objects(data);
        if(data->wall_flag != 1 || data->back_flag != 1 || data->collect_flag != 1 || data->player_flag != 1 || data->exit_flag != 1)
                return 1;
        else if(check_rectangle(data) == 1)
                return 1;
        else if(check_border(data) == 1)
                return 1;
        return 0;
}