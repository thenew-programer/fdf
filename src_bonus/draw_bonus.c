/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:14:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/13 11:05:36 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * data->bpp / 8);
		*(unsigned int *)dst = color;
	}
}

void	draw_line_segment(t_fdf *data, t_point *p1, t_point *p2, t_point *delta)
{
	t_point	sign;
	int		err[2];

	sign.x = 1;
	sign.y = 1;
	if (p1->x > p2->x)
		sign.x = -1;
	if (p1->y > p2->y)
		sign.y = -1;
	err[0] = delta->x - delta->y;
	while (p1->x != p2->x || p1->y != p2->y)
	{
		pixel_put(data->img_ptr, p1->x, p1->y, p_color(p1, p2));
		err[1] = err[0] * 2;
		if (err[1] > -delta->y)
		{
			err[0] -= delta->y;
			p1->x += sign.x;
		}
		if (err[1] < delta->x)
		{
			err[0] += delta->x;
			p1->y += sign.y;
		}
	}
}

void	draw_line(t_fdf *data, t_point p1, t_point p2)
{
	t_point	delta;

	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	draw_line_segment(data, &p1, &p2, &delta);
}

void	draw_background(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH - MENU_WIDTH)
		{
			pixel_put(data->img_ptr, x, y, BACKGROUND);
			x++;
		}
		y++;
	}
}

void	draw_shape(t_fdf *data)
{
	int	x;
	int	y;

	draw_background(data);
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (x != data->cols - 1)
				draw_line(data, project(data, data->map[y][x]),
					project(data, data->map[y][x + 1]));
			if (y != data->rows - 1)
				draw_line(data, project(data, data->map[y][x]),
					project(data, data->map[y + 1][x]));
			x++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr->img, MENU_WIDTH, 0);
		y++;
	}
}
