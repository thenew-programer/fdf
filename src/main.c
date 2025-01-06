/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:38 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/04 14:20:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

// int	main(int ac, char **av)
// {
// 	t_point	*map;
//
// 	if (ac != 2)
// 		return (1);
// 	map = parser(ac, av);
// 	if (map == NULL)
// 		return (1);
// 	map_print(map);
// 	map_free(&map);
// 	return (0);
// }
int	get_opposite(int color)
{
	int	red;
	int	blue;
	int	green;
	int	alpha;

	alpha = (color >> 24) & 0xFF;
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color & 0xFF);
	red = 0xFF - red;
	green = 0xFF - green;
	blue = 0xFF - blue;
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *img, int init_x, int init_y, int color, int w, int h)
{
	int	i;
	int	j;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < h; j++)
		{
			if (i <= 5 || i >= w - 5)
				pixel_put(img, init_x + i, init_y + j, color);
			if (j <= 5 || j >= h - 5)
				pixel_put(img, init_x + i, init_y + j, color);

		}
	}
}

void	draw_circle(t_data *img, int init_x, int init_y, int color, int radius)
{
	int	diameter = 2 * radius + 1;
	int	x;
	int	y;

	x = 0;
	init_y = init_y - radius;
	init_x = init_x - radius;
	while (x < diameter)
	{
		y = 0;
		while (y < diameter)
		{
			int dx = x - radius;
			int dy = y - radius;
			if (sqrt(dx * dx + dy * dy) >= radius - 5 && sqrt(dx * dx + dy * dy) <= radius)
				pixel_put(img, init_x + x, init_y + y, get_opposite(color));
			y++;
		}
		x++;
	}
}

void	draw_circles(t_data *img, int init_x, int init_y, int color, int spacing, int radius, int w, int h)
{
	for (int r = spacing; r < fmin(w, h); r += spacing)
	{
		draw_circle(img, init_x + r, init_y + r, color , radius);
	}
}

int	add_shade(double distance, int color)
{
	int	red;
	int	blue;
	int	green;
	int	alpha;

	if (distance < 0.0)
		distance = 0.0;
	if (distance > 1.0)
		distance = 1.0;
	alpha = (color >> 24) & 0xFF;
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color & 0xFF);
	red = (int)(red * (1.0 - distance));
	green = (int)(green * (1.0 - distance));
	blue = (int)(blue * (1.0 - distance));
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_vars;
int	keyhook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	printf("keycode = %d\n", keycode);
	return (0);
}

int	mousehook(int button, int x, int y, t_vars *vars)
{
	if ((x >= 350 && x <= 400) && (y >= 0 && y <= 10) && button)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	printf("x = %d - y = %d [button = %d]\n", x, y, button);
	draw_circle(vars->img, x, y, add_shade(0.0, 0x00FF0000), 20);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
int	main()
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_vars	vars;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 400, 400, "FdF");
	img.img = mlx_new_image(mlx, 1200, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// draw_square(&img, 100, 50, add_shade(0.5, 0x00111111), 1000, 600);
	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	// draw_square(&img, 350, 200, add_shade(0.5, 0x00FFFFFF), 500, 300);
	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	// draw_circle(&img, 600, 350, add_shade(0.0, 0x00FF0000), 80);
	// draw_circles(&img, 100, 50, add_shade(0.5, 0x00FF6F61), 10, 50, 1000, 600);
	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_window;
	vars.img = &img;
	mlx_key_hook(mlx_window, keyhook, &vars);
	mlx_mouse_hook(mlx_window, mousehook, &vars);
	mlx_loop(mlx);
}

