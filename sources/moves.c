#include "so_long.h"

/* static void print_map(char **map)
{
        int i;
        int x;

        i = 0;
        x = 0;
        while(map[i])
        {
                x = 0;
                while(map[i][x])
                {
                        printf("%c", map[i][x]);
                        x++;
                }
                printf("\n");
                i++;
        }
}
 */
static int verify_move(t_data *data, int x, int y)
{
        if(data->map[y][x] == '1' || x < 0 || y < 0)
                return 1;
        return 0;
}

void move_right(t_data *data, int x, int y)
{
        int temp;

        temp = x + 1;
        if(verify_move(data, temp, y) == 0)
        {
                data->map[y][x] = '0';
                img_draw(data, data->back, x, y);
                x++;
                data->map[y][x] = 'P';
                img_draw(data, data->player, x, y);
        }
        return ;
}

void move_left(t_data *data, int x, int y)
{
        int temp;

        temp = x - 1;
        if(verify_move(data, temp, y) == 0)
        {
                data->map[y][x] = '0';
                img_draw(data, data->back, x, y);
                x--;
                data->map[y][x] = 'P';
                img_draw(data, data->player, x, y);
        }
        return ;
}

void move_up(t_data *data, int x, int y)
{
        int temp;

        temp = y - 1;
        if(verify_move(data, x, temp) == 0)
        {
                data->map[y][x] = '0';
                img_draw(data, data->back, x, y);
                y--;
                data->map[y][x] = 'P';
                img_draw(data, data->player, x, y);
        }
        return ;
}

void move_down(t_data *data, int x, int y)
{
        int temp;

        temp = y + 1;
        if(verify_move(data, x, temp) == 0)
        {
                data->map[y][x] = '0';
                img_draw(data, data->back, x, y);
                y++;
                data->map[y][x] = 'P';
                img_draw(data, data->player, x, y);
        }
        return ;
}