#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# define ESC 65307

#ifndef LENGTH
#define LENGTH 640
#endif

#ifndef HEIGHT
#define HEIGHT 360
#endif

typedef struct s_data
{
        void    *mlx;
        void    *win;
        char    **map;
        int     width;
        int     height;
        void    *wall;
        void    *back;
        void    *player;
        void    *collect;
        void    *exit;
        int     wall_flag;
        int     back_flag;
        int     player_flag;
        int     collect_flag;
        int     exit_flag;
}                                       t_data;

void init_game(t_data *map);
void read_map(t_data *data, char *path);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int map_draw(t_data *data);
void img_draw(t_data *data, void *img, int x, int y);
void gameplay(t_data *data);
//moves
void move_right(t_data *data, int x, int y);
void move_left(t_data *data, int x, int y);
void move_up(t_data *data, int x, int y);
void move_down(t_data *data, int x, int y);
int close_game(t_data *data);
void free_map(t_data *data);
int check_map(t_data* data);

#endif