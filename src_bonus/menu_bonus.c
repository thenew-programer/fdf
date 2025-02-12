/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:01:47 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:23:01 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	menu_info(t_fdf *data)
{
	data->menu->top_margin = HEIGHT / 6;
	data->menu->left_margin = MENU_WIDTH / 8;
}

void	menu_help_text(t_fdf *data)
{
	int		t_margin;
	int		l_margin;
	void	*mlx;
	void	*win;

	menu_info(data);
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	header_help(data);
	rotate_help(data);
	project_help(data);
	translate_help(data);
	zoom_help(data);
	mlx_string_put(mlx, win, l_margin, t_margin + 460, MENU_TEXT, "Altitude");
	mlx_string_put(mlx, win, l_margin, t_margin + 460, MENU_TEXT, "Altitude");
	mlx_string_put(mlx, win, l_margin + 15,
		t_margin + 480, MENU_TEXT, "- Iso: <f>/<S-f>");
	mlx_string_put(mlx, win, l_margin, t_margin + 510, MENU_TEXT, "Depth");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 510, MENU_TEXT, "Depth");
	mlx_string_put(mlx, win, l_margin + 15,
		t_margin + 530, MENU_TEXT, "- Conic: <t>/<S-t>");
	reset_help(data);
	exit_help(data);
}

void	draw_menu_background(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < MENU_WIDTH)
		{
			pixel_put(data->menu->img_ptr, x, y, MENU_COLOR);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->menu->img_ptr->img, 0, 0);
}

void	draw_menu(t_fdf *data)
{
	draw_menu_background(data);
	menu_help_text(data);
}
