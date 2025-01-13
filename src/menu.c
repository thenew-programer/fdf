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

void	draw_menu(t_fdf *data)
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu->img_ptr->img, 0, 0);
	// mlx_set_font(data->mlx_ptr, data->win_ptr, "FiraCode Nerd Font");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, TEXT, "FDF");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 50, TEXT, "ROTATE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 80, TEXT, "PROJECT");
}
