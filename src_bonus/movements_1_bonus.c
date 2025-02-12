/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:41 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:39:19 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate(t_fdf *data)
{
	double	angle;

	angle = PI / 180;
	if (data->keys->pk_key == XK_x && data->keys->pk_shift)
		data->screen->alpha -= angle;
	else if (data->keys->pk_key == XK_x)
		data->screen->alpha += angle;
	if (data->keys->pk_key == XK_y && data->keys->pk_shift)
		data->screen->beta -= angle;
	else if (data->keys->pk_key == XK_y)
		data->screen->beta += angle;
	if (data->keys->pk_key == XK_z && data->keys->pk_shift)
		data->screen->gamma -= angle;
	else if (data->keys->pk_key == XK_z)
		data->screen->gamma += angle;
}

void	depth(t_fdf *data)
{
	int	min_d;
	int	max_d;

	min_d = 0;
	max_d = 20;
	if (data->keys->pk_key == XK_t && data->keys->pk_shift)
	{
		if (data->screen->depth > min_d)
			data->screen->depth--;
	}
	else if (data->keys->pk_key == XK_t)
	{
		if (data->screen->depth < max_d)
			data->screen->depth++;
	}
}

void	adjust_translate(t_fdf *data)
{
	int	w;
	int	h;

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

void	translate(t_fdf *data)
{
	int	step;

	step = 10;
	if (data->keys->pk_key == XK_w || data->keys->pk_key == XK_Up)
	{
		data->screen->offset_y -= step;
		adjust_translate(data);
	}
	if (data->keys->pk_key == XK_s || data->keys->pk_key == XK_Down)
	{
		data->screen->offset_y += step;
		adjust_translate(data);
	}
	if (data->keys->pk_key == XK_a || data->keys->pk_key == XK_Left)
	{
		data->screen->offset_x -= step;
		adjust_translate(data);
	}
	if (data->keys->pk_key == XK_d || data->keys->pk_key == XK_Right)
	{
		data->screen->offset_x += step;
		adjust_translate(data);
	}
}

void	projection(t_fdf *data)
{
	if (data->keys->pk_key == XK_i)
		data->screen->projection = ISOMETRIC;
	if (data->keys->pk_key == XK_c)
		data->screen->projection = CONIC;
	if (data->keys->pk_key == XK_p)
		data->screen->projection = PARALLEL;
}
