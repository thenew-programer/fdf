/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:39:24 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:39:31 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	altitude(t_fdf *data)
{
	float	step;

	step = 0.2;
	if (data->keys->pk_key == XK_f && data->keys->pk_shift)
		data->screen->z_div -= step;
	else if (data->keys->pk_key == XK_f)
		data->screen->z_div += step;
}

void	reset(t_fdf *data)
{
	int	size_w;
	int	size_h;

	if (data->keys->pk_key == XK_r)
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
		data->screen->depth = 0;
	}
}

int	close_window(t_fdf *data)
{
	if (data->keys->pk_key == XK_Escape)
	{
		free_fdf_data(data);
		exit(0);
	}
	return (0);
}

int	cross_exit(t_fdf *data)
{
	data->keys->pk_key = XK_Escape;
	return (0);
}
