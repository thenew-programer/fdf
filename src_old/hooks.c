/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:09:55 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/06 19:33:02 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/keysym.h>

int	close_window(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr->img);
	free(data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	map_free(data->map);
	free(data);
	exit(0);
}

int	keyhook(int keycode, t_fdf *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	return (0);
}
