#include "so_long.h"


/* int	key_pressed(int key, t_win *win)
{
        (void)win;
        printf("Button pressed (%d)!\n", key);
        if(key == 65307)
                mlx_destroy_window(win->mlx, win->mlx_win);
        return 0;
}

//Esta main esta a criar uma janela com a cor vermelha e rosa e regista as keys pressionadas
int	main(void)
{
        t_win map;
	t_data	img;
        int x;
        int y;

        y = 0;
        init_win(&map);
	img.img = mlx_new_image(map.mlx, LENGTH , HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
        while(y < HEIGHT / 4)
        {
                x = 0;
                while(x < LENGTH)
                {
                        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
                        x++;
                }
                y++;
        }
        while(y < HEIGHT)
        {
                x = 0;
                while(x < LENGTH)
                {
                        my_mlx_pixel_put(&img, x, y, 0x00FF00FF);
                        x++;
                }
                y++;
        }
	mlx_put_image_to_window(map.mlx, map.mlx_win, img.img, 0, 0);
        //MLX_HOOK --> Vai ler a KEY que foi pressionada no teclado e chamar a funcao "key_pressed"
        mlx_hook(map.mlx_win, 2, 1L<<0, &key_pressed, &map);
	mlx_loop(map.mlx);
} */


//Vai registar as keys pressionadas na window
/* int	key_hook(int keycode, t_win *vars)
{
        (void)keycode;
        (void)vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	mouse_hook(int keycode, t_win *vars)
{
        (void)keycode;
        (void)vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 640, 480, "Hello world!");
        //Vai chamar a funcao "key_hook" assim que der release na tecla
	mlx_key_hook(win.mlx_win, key_hook, &win);
        //Vai chamar a funcao "mouse_hook" assim que clicar na tecla
        mlx_mouse_hook(win.mlx_win, mouse_hook, &win);
	mlx_loop(win.mlx);
} */


// Vai criar uma janaela que vai mudar de cor a cada segundo (rosa -> verde -> azul)
/* void screen_color(t_data *img, long int color)
{
        int y;
        int x;

        y = 0;
        while(y < HEIGHT)
        {
                x = 0;
                while(x < LENGTH)
                {
                        my_mlx_pixel_put(img, x, y, color);
                        x++;
                }
                y++;
        }
}

int change_color(t_data *img)
{
        if(img->color == 0x00FF00FF || img->color == 0)
                img->color = 0x0000FF1A;
        else if(img->color == 0x0000FF1A)
                img->color = 0x0000ABFF;
        else if(img->color == 0x0000ABFF)
                img->color = 0x00FF00FF;
        
        screen_color(img, img->color);
        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
        return 0;
}

int main ()
{
        t_data img;

        img.color = 0;
        img.mlx = mlx_init();
        img.mlx_win = mlx_new_window(img.mlx, LENGTH, HEIGHT, "Hello World");
        img.img = mlx_new_image(img.mlx, LENGTH , HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
        mlx_loop_hook(img.mlx, change_color, &img);
        mlx_loop(img.mlx);
} */

/* int main()
{
        t_data data;
        char *img_path = "./sus.png";
        init_win(&data);
        data.img = mlx_new_image(data.mlx, LENGTH, HEIGHT);
        data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

        mlx_loop(data.mlx);
} */

/* void screen_color(t_data *img, unsigned int color)
{
        int y;
        int x;

        y = 0;
        while(y < HEIGHT)
        {
                x = 0;
                while(x < LENGTH)
                {
                        my_mlx_pixel_put(img, x, y, color);
                        x++;
                }
                y++;
        }
} */

int main(int argc, char **argv)
{
        t_data data;
        if(argc > 1 && argc < 3)
        {
                read_map(&data, argv[1]);
                if(check_map(&data) == 0)
                {
                        init_game(&data);
                        gameplay(&data);
                        mlx_loop(data.mlx);
                }
                else
                        free_map(&data);
        }
}       