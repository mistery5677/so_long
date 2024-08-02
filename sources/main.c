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

void test()
{

}

int change_color(t_data *img)
{
        int y = 0;
        int x;
        printf("function addr %s\n", img->addr);
        while(y < HEIGHT)
        {
                x = 0;
                while(x < LENGTH)
                {
                        my_mlx_pixel_put(img,  x, y, 0x00FF00FF);
                        x++;
                }
                y++;
        }
        return 0;
}

int main ()
{
        t_data img;

        img.mlx = mlx_init();
        img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello World");
        img.img = mlx_new_image(img.mlx, LENGTH , HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
        printf("main addr %s\n", img.addr);
        mlx_loop_hook(img.mlx, change_color, &img);
        mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
        mlx_loop(img.mlx);
}