/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:19:06 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:52:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->pk_shift = 1;
	else if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->pk_ctrl = 1;
	else
		data->keys->pk_key = keycode;
	return (0);
}

int	key_release(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->pk_shift = 0;
	else if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->pk_ctrl = 0;
	else if (keycode == data->keys->pk_key)
		data->keys->pk_key = 0;
	return (0);
}
