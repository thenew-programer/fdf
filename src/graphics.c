/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:13:50 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 09:13:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include "fdf.h"
#include "mlx.h"

void	free_graphics(t_fdf *data)
{
	if (data)
	{
		if (data->menu->img_ptr)
			if (data->menu->img_ptr->img)
				mlx_destroy_image(data->mlx_ptr, data->menu->img_ptr->img);
		if (data->img_ptr)
			if (data->img_ptr->img)
				mlx_destroy_image(data->mlx_ptr, data->img_ptr->img);
		if (data->win_ptr)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
		if (data->mlx_ptr)
			mlx_destroy_display(data->mlx_ptr);
	}
}

void	init_screen(t_fdf *data)
{
	t_screen	*screen;
	int			size_w;
	int			size_h;

	screen = (t_screen *)malloc(sizeof(t_screen));
	if (!screen)
		die(MALLOC_ERR, data);
	size_w = (WIDTH - MENU_WIDTH) / data->cols / 2;
	size_h = HEIGHT / data->rows / 2;
	screen->zoom = min(size_w, size_h);
	screen->alpha = 0;
	screen->beta = 0;
	screen->gamma = 0;
	screen->z_div = 1;
	// screen->offset_x = ((WIDTH - MENU_WIDTH) - screen->zoom * data->cols) / 2;
	// screen->offset_y = (HEIGHT - screen->zoom * data->rows) / 2;
	screen->offset_x = 0;
	screen->offset_y = 0;
	screen->angle = 0.523599;
	screen->projection = ISOMETRIC;
	data->screen = screen;
}

t_img_data	*init_img(t_fdf *data, int width, int height)
{

	t_img_data	*img_ptr;

	img_ptr = (t_img_data *)malloc(sizeof(t_img_data));
	if (!img_ptr)
		die(MALLOC_ERR, data);
	img_ptr->img = mlx_new_image(data->mlx_ptr, width, height);
	if (!img_ptr->img)
		die(MLX_IMAGE_ERR, data);
	img_ptr->addr = mlx_get_data_addr(img_ptr->img,
										&img_ptr->bpp,
										&img_ptr->line_length,
										&img_ptr->endian);
	return (img_ptr);
}

t_menu	*init_menu(t_fdf *data)
{
	t_menu	*menu;

	if (MENU_WIDTH == 0)
		return (NULL);
	menu = (t_menu *)malloc(sizeof(t_menu));
	if (!menu)
		die(MALLOC_ERR, data);
	menu->img_ptr = init_img(data, MENU_WIDTH, HEIGHT);
	return (menu);
}

void	init_graphics(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		die(MLX_DISPLAY_ERR, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, data->w_title);
	if (!data->win_ptr)
		die(MLX_WINDOW_ERR, data);
	data->img_ptr = init_img(data, WIDTH - MENU_WIDTH, HEIGHT);
	data->menu = init_menu(data);
	mlx_key_hook(data->win_ptr, keyhook, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	/* close display when clicking on the x button */
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	init_screen(data);
}