/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:19:06 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 10:39:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

int	key_press(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->PK_shift = 1;
	else if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->PK_ctrl = 1;
	else
		data->keys->PK_key = keycode;
	return (0);
}

int	key_release(int keycode, t_fdf *data)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		data->keys->PK_shift = 0;
	else if (keycode == XK_Control_L || keycode == XK_Control_R)
		data->keys->PK_ctrl = 0;
	else if (keycode == data->keys->PK_key)
		data->keys->PK_key = 0;
	return (0);
}

// void	init_keycodes(int *keys)
// {
// 	keys[0] = XK_r;
// 	keys[1] = XK_minus;
// 	keys[2] = XK_plus;
// 	keys[3] = XK_c;
// 	keys[4] = XK_x;
// 	keys[5] = XK_y;
// 	keys[6] = XK_z;
// 	keys[7] = XK_p;
// 	keys[8] = XK_i;
// 	keys[9] = XK_w;
// 	keys[10] = XK_a;
// 	keys[11] = XK_s;
// 	keys[12] = XK_d;
// 	keys[13] = XK_Up;
// 	keys[14] = XK_Down;
// 	keys[15] = XK_Right;
// 	keys[16] = XK_Left;
// 	keys[17] = XK_Escape;
// }
//
// void	init_key_fields(t_fdf *data, int **key_fields)
// {
// 	key_fields[0] = &data->keys->PK_r;
// 	key_fields[1] = &data->keys->PK_minus;
// 	key_fields[2] = &data->keys->PK_plus;
// 	key_fields[3] = &data->keys->PK_c;
// 	key_fields[4] = &data->keys->PK_x;
// 	key_fields[5] = &data->keys->PK_y;
// 	key_fields[6] = &data->keys->PK_z;
// 	key_fields[7] = &data->keys->PK_p;
// 	key_fields[8] = &data->keys->PK_i;
// 	key_fields[9] = &data->keys->PK_w;
// 	key_fields[10] = &data->keys->PK_a;
// 	key_fields[11] = &data->keys->PK_s;
// 	key_fields[12] = &data->keys->PK_d;
// 	key_fields[13] = &data->keys->PK_up;
// 	key_fields[14] = &data->keys->PK_down;
// 	key_fields[15] = &data->keys->PK_right;
// 	key_fields[16] = &data->keys->PK_left;
// 	key_fields[17] = &data->keys->PK_Escape;
// }
//
// int	key_press(int keycode, t_fdf *data)
// {
// 	int	keys[18];
// 	int	*key_fields[18];
// 	int	i;
//
// 	init_keycodes(keys);
// 	init_key_fields(data, key_fields);
//
// 	i = 0;
// 	while (i < 18)
// 	{
// 		if (keycode == keys[i])
// 		{
// 			*(key_fields[i]) = 1;
// 			return (0);
// 		}
// 		i++;
// 	}
// 	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
// 		data->keys->PK_shift = 1;
// 	if (keycode == XK_Control_L || keycode == XK_Control_R)
// 		data->keys->PK_ctrl = 1;
// 	return (0);
// }
//
// int	key_release(int keycode, t_fdf *data)
// {
// 	int	keycodes[18];
// 	int	*key_fields[18];
// 	int	i;
//
// 	init_keycodes(keycodes);
// 	init_key_fields(data, key_fields);
//
// 	i = 0;
// 	while (i < 18)
// 	{
// 		if (keycode == keycodes[i])
// 		{
// 			*(key_fields[i]) = 0;
// 			return (0);
// 		}
// 		i++;
// 	}
// 	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
// 		data->keys->PK_shift = 0;
// 	if (keycode == XK_Control_L || keycode == XK_Control_R)
// 		data->keys->PK_ctrl = 0;
// 	return (0);
// }
