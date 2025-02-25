/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:57:05 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:41:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data, t_point *p)
{
	int		prev_x;
	int		prev_y;
	double	angle;

	angle = data->screen->angle;
	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(angle) + prev_y
		* cos(angle + 2) + p->z * cos(angle - 2);
	p->y = prev_x * sin(angle) + prev_y
		* sin(angle + 2) + p->z * sin(angle - 2);
}

void	_rotate(t_fdf *data, t_point *p)
{
	int	prev_x;
	int	prev_y;
	int	prev_z;

	prev_x = p->x;
	prev_y = p->y;
	prev_z = p->z;
	p->y = prev_y * cos(data->screen->alpha)
		- prev_z * sin(data->screen->alpha);
	p->z = prev_z * cos(data->screen->alpha)
		+ prev_y * sin(data->screen->alpha);
	prev_y = p->y;
	prev_z = p->z;
	p->x = prev_x * cos(data->screen->beta)
		+ prev_z * sin(data->screen->beta);
	p->z = prev_z * cos(data->screen->beta)
		- prev_x * sin(data->screen->beta);
	prev_x = p->x;
	p->x = prev_x * cos(data->screen->gamma)
		- prev_y * sin(data->screen->gamma);
	p->y = prev_y * cos(data->screen->gamma)
		+ prev_x * sin(data->screen->gamma);
}

t_point	project(t_fdf *data, t_point p)
{
	p.x *= data->screen->zoom;
	p.y *= data->screen->zoom;
	p.z *= (int)(data->screen->zoom / data->screen->z_div);
	p.x -= (data->cols * data->screen->zoom) / 2;
	p.y -= (data->rows * data->screen->zoom) / 2;
	_rotate(data, &p);
	isometric(data, &p);
	p.x += (WIDTH - MENU_WIDTH) / 2 + data->screen->offset_x;
	p.y += (HEIGHT + data->rows * data->screen->zoom) / 2
		+ data->screen->offset_y;
	return (p);
}
