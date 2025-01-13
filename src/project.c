/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:57:05 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 17:00:06 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data, t_point *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(data->screen->angle);
	p->y = (prev_x + prev_y) * sin(data->screen->angle) - p->z;
}
void	rotate(t_fdf *data, t_point *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	/* Rotation of the x axis */
	p->y = prev_y * cos(data->screen->alpha) + p->z * sin(data->screen->alpha);
	p->z = p->z * cos(data->screen->alpha) + prev_y * sin(data->screen->alpha);
	/*Rotationof the y ordinate */
	p->x = prev_x * cos(data->screen->beta) + p->z * sin(data->screen->beta);
	p->z = p->z * cos(data->screen->beta) + prev_x * sin(data->screen->beta);
	/*Rotationof the y altitude */
	p->x = prev_x * cos(data->screen->gamma) + prev_y * sin(data->screen->gamma);
	p->y = prev_y * cos(data->screen->gamma) + prev_x * sin(data->screen->gamma);
}

t_point	project(t_fdf *data, t_point p)
{
	p.x *= data->screen->zoom;
	p.y *= data->screen->zoom;
	p.z *= data->screen->zoom / data->screen->z_div;
	p.x -= (data->cols * data->screen->zoom) / 2;
	p.y -= (data->rows * data->screen->zoom) / 2;
	rotate(data, &p);
	isometric(data, &p);
	p.x += (WIDTH - MENU_WIDTH) / 2 + data->screen->offset_x;
	p.y += (HEIGHT + data->rows * data->screen->zoom) / 2 + data->screen->offset_y;
	return (p);
}
