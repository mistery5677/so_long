#include "so_long.h"

/* int main()
{
        t_game *game;

        game = NULL;
        game->mlx = mlx_init();
        game->window = mlx_new_window(game->mlx, 1920, 1080, "Hello World");
        mlx_loop(game->mlx);
} */

int main()
{
        void *mlx;
        void *mlx_win;

        mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
        (void)mlx_win;
	mlx_loop(mlx);
}