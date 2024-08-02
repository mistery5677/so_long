#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>

#ifndef LENGTH
#define LENGTH 1920
#endif

#ifndef HEIGHT
#define HEIGHT 1080
#endif

typedef struct s_data
{
        void    *mlx;
        void    *mlx_win;
        void    *img;
        char    *addr;
        int     bits_per_pixel;
        int     line_length;
        int     endian;
}                                       t_data;

void init_win(t_data *map);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif