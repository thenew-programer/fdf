/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:41 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 10:41:24 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *data)
{
	double	angle;

	angle = PI / 180;
	if (data->keys->PK_key == XK_x && data->keys->PK_shift)
		data->screen->alpha -= angle;
	else if (data->keys->PK_key == XK_x)
		data->screen->alpha += angle;
	if (data->keys->PK_key == XK_y && data->keys->PK_shift)
		data->screen->beta -= angle;
	else if (data->keys->PK_key == XK_y)
		data->screen->beta += angle;
	if (data->keys->PK_key == XK_z && data->keys->PK_shift)
		data->screen->gamma -= angle;
	else if (data->keys->PK_key == XK_z)
		data->screen->gamma += angle;
}

void	translate(t_fdf *data)
{
	int w;
	int h;
	int	step;

	step = 10;
	if (data->keys->PK_key == XK_w || data->keys->PK_key == XK_Up)
		data->screen->offset_y -= step;
	if (data->keys->PK_key == XK_s || data->keys->PK_key == XK_Down)
		data->screen->offset_y += step;
	if (data->keys->PK_key == XK_a || data->keys->PK_key == XK_Left)
		data->screen->offset_x -= step;
	if (data->keys->PK_key == XK_d || data->keys->PK_key == XK_Right)
		data->screen->offset_x += step;
	w = WIDTH - MENU_WIDTH;
	h = HEIGHT;
	if (data->screen->offset_x < -w / 2)
		data->screen->offset_x += w;
	else if (data->screen->offset_x > w / 2)
		data->screen->offset_x -= w;
	if (data->screen->offset_y < -h / 2)
		data->screen->offset_y += h;
	else if (data->screen->offset_y > h / 2)
		data->screen->offset_y -= h;
}

void	projection(t_fdf *data)
{
	if (data->keys->PK_key == XK_i)
		data->screen->projection = ISOMETRIC;
	if (data->keys->PK_key == XK_c)
		data->screen->projection = CONIC;
	if (data->keys->PK_key == XK_p)
		data->screen->projection = PARALLEL;
}

void	zoom(t_fdf *data)
{
	int	min_z;
	int	max_z;
	int	step;

	step = 1;
	min_z = 1;
	max_z = 15;
	if (data->keys->PK_key == XK_minus)
		if (data->screen->zoom > min_z)
			data->screen->zoom -= step;
	if (data->keys->PK_key == '=' && data->keys->PK_shift)
		if (data->screen->zoom < max_z)
			data->screen->zoom += step;
}

void	flatten(t_fdf *data)
{
	float	step;

	step = 0.2;
	if (data->keys->PK_key == XK_f && data->keys->PK_shift)
		data->screen->z_div -= step;
	else if (data->keys->PK_key == XK_f)
		data->screen->z_div += step;
}

void	reset(t_fdf *data)
{
	int	size_w;
	int	size_h;

	if (data->keys->PK_key == XK_r)
	{
		data->screen->alpha = 0.0;
		data->screen->beta = 0.0;
		data->screen->gamma = 0.0;
		size_w = (WIDTH - MENU_WIDTH) / data->cols / 2;
		size_h = HEIGHT / data->rows / 2;
		data->screen->zoom = min(size_w, size_h);
		data->screen->offset_x = 0;
		data->screen->offset_y = 0;
		data->screen->z_div = 1.0;
	}
}

int	close_window(t_fdf *data)
{
	if (data->keys->PK_key == XK_Escape)
	{
		free_fdf_data(data);
		exit(0);
	}
	return (0);
}
