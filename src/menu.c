/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:01:47 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/13 11:49:52 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	menu_info(t_fdf *data)
{
	data->menu->top_margin = HEIGHT / 6;
	data->menu->left_margin = MENU_WIDTH / 8;
}
void	draw_menu(t_fdf *data)
{
	int	x;
	int	y;
	int	t_margin;
	int	l_margin;

	menu_info(data);
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
	t_margin = data->menu->top_margin;
	l_margin = data->menu->left_margin;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu->img_ptr->img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, l_margin, t_margin + 20, TEXT, "FDF");
	mlx_string_put(data->mlx_ptr, data->win_ptr, l_margin, t_margin + 50, TEXT, "ROTATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, l_margin, t_margin + 80, TEXT, "PROJECT");
}
