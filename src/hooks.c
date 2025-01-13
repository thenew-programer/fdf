/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:19:06 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/13 15:02:26 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

int	close_window(t_fdf *data)
{
	free_fdf_data(data);
	exit(0);
}

int	keyhook(int keycode, t_fdf *data)
{
	int	size_w;
	int	size_h;

	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_Up || keycode == XK_w)
		data->screen->offset_y -= 10;
	if (keycode == XK_Down || keycode == XK_s)
		data->screen->offset_y += 10;
	if (keycode == XK_Right || keycode == XK_a)
		data->screen->offset_x += 10;
	if (keycode == XK_Left || keycode == XK_d)
		data->screen->offset_x -= 10;
	if (keycode == XK_x)
		data->screen->alpha += 0.0873;
	if (keycode == XK_y)
		data->screen->beta += 0.0873;
	if (keycode == XK_z)
		data->screen->gamma += 0.0873;
	if (keycode == XK_X)
		data->screen->alpha -= 0.0873;
	if (keycode == XK_Y)
		data->screen->beta -= 0.0873;
	if (keycode == XK_Z)
		data->screen->gamma -= 0.0873;
	if (keycode == XK_r)
	{
		data->screen->alpha = 0.0;
		data->screen->beta = 0.0;
		data->screen->gamma = 0.0;
		size_w = (WIDTH - MENU_WIDTH) / data->cols / 2;
		size_h = HEIGHT / data->rows / 2;
		data->screen->zoom = min(size_w, size_h);
		data->screen->offset_x = 0;
		data->screen->offset_y = 0;
	}
	if (keycode == '=')
		data->screen->zoom++;
	if (keycode == XK_minus)
		data->screen->zoom--;
	return (0);
}

int	key_press(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->PK_shift = 0;
	if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->PK_ctrl = 0;
	return (0);
}
int	key_release(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->PK_shift = 0;
	if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->PK_ctrl = 0;
	return (0);
}
