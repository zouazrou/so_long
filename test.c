#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <X11/keysym.h>

#define LENGTH	10
#define WIDTH	10

typedef struct s_img
{

	void	*img_ptr;
}			t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_var;

int	func(int keysym, t_var *param)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_display(param->mlx);
		mlx_destroy_window(param->mlx, param->win);
		// mlx_destroy_image(param->mlx, param->img.img_ptr);
		free(param->img.img_ptr);
		exit ((free(param->mlx), 1));
	}
	else
		return (printf("the keycode : %d\n", keysym), 0);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img_ptr, 64, 64);
	return (0);
}

int	main(void)
{
	t_var	win;
	int x, y;


	win.mlx = mlx_init();
	if (!win.mlx)
		exit (1);

	win.win = mlx_new_window(win.mlx, LENGTH * 64, WIDTH * 64, "waaa3");
	if (!win.win)
	{
		mlx_destroy_display(win.mlx);
		exit((free(win.mlx), 1));
	}

	// create img
	win.img.img_ptr = mlx_new_image(win.mlx, 64, 64);


	// Load xpm image
	win.img.img_ptr = mlx_xpm_file_to_image(win.mlx, "./textures/Brown.xpm", &x, &y);
	printf("%d-%d\n", x, y);

	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			mlx_put_image_to_window(win.mlx, win.win, win.img.img_ptr, 64 * x, 64 * y);
		}
	}

	// wall
	t_var wall;
	wall.img.img_ptr = mlx_new_image(win.mlx, 64, 64);
	wall.img.img_ptr = mlx_xpm_file_to_image(win.mlx, "./textures/coll.xpm", &x, &y);
	mlx_put_image_to_window(win.mlx, win.win, wall.img.img_ptr, 64 * 0, 64 * 0);
	mlx_put_image_to_window(win.mlx, win.win, wall.img.img_ptr, 64 * 0, 64 * 1);

	mlx_key_hook(win.win, func, &win);
	mlx_loop(win.mlx);

	mlx_destroy_display(win.mlx);
	mlx_destroy_window(win.mlx, win.win);
	free(win.mlx);
	return (0);

}
