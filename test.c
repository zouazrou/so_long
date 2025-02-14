#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <X11/keysym.h>

#define LENGTH	500
#define WIDTH	500

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	xpm_img;
	int		img_width;
	int		img_length;
}			t_var;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}
void	col_scr(int color, t_var *param)
{
	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			my_pixel_put(&param->img, x, y, color);;
		}
	}
}
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
	else if (keysym == XK_r)
		col_scr(0xff0000, param);
	else if (keysym == XK_b)
		col_scr(0x0000ff, param);
	else if (keysym == XK_g)
		col_scr(0x00ff00, param);
	else
		return (printf("the keycode : %d\n", keysym), 0);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img_ptr, 0, 4);
	return (0);
}

int	main(void)
{
	t_var	win;


	win.mlx = mlx_init();
	if (!win.mlx)
		exit (1);

	win.win = mlx_new_window(win.mlx, LENGTH, WIDTH, "another one");
	if (!win.win)
	{
		mlx_destroy_display(win.mlx);
		exit((free(win.mlx), 1));
	}
	int x, y;

	// create img
	win.img.img_ptr = mlx_new_image(win.mlx, WIDTH, LENGTH);
	win.img.img_pixels_ptr = mlx_get_data_addr(win.img.img_ptr,
													&win.img.bits_per_pixel,
													&win.img.line_len,
													&win.img.endian);

	// Load xpm image

	win.img.img_ptr = mlx_xpm_file_to_image(win.mlx, "./textures/Brown.xpm", &x, &y);

	mlx_put_image_to_window(win.mlx, win.win, win.img.img_ptr, 0, 2);

	mlx_key_hook(win.win, func, &win);

	// win.img.img_ptr = mlx_xpm_file_to_image(win.mlx, "./textures/Brown.xpm", &x, &y);
	// mlx_put_image_to_window(win.mlx, win.win, win.img.img_ptr, 0, 1);

	printf("%d %d\n", x, y);
	mlx_loop(win.mlx);

	mlx_destroy_display(win.mlx);
	mlx_destroy_window(win.mlx, win.win);
	free(win.mlx);
	return (0);

}
