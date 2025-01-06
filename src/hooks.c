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

int	close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	map_free(data->map);
	exit(0);
}

int	keyhook(int keycode, t_mlx_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	return (0);
}

int	mousehook(int button, int x, int y, t_mlx_data *data)
{
	return (0);
}
