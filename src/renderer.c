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
	return (0);
}

int	render(t_fdf *data)
{
	if (data->keys->pk_key == XK_Escape)
		close_window(data);
	return (0);
}
