/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:16:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 10:41:35 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw(t_fdf *data)
{
	draw_shape(data);
	draw_menu(data);
	return (0);
}

int	render(t_fdf *data)
{
	if (data->keys->pk_key)
	{
		zoom(data);
		rotate(data);
		translate(data);
		projection(data);
		altitude(data);
		depth(data);
		reset(data);
		close_window(data);
		draw_shape(data);
	}
	return (0);
}
