/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:13:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/10 10:58:45 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"


t_point	*project(t_point *p)
{
	isometric_projection(p);
	return (p);
}


void	draw_line(t_mlx_data *vars, t_point *p1, t_point *p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err[2];

	sx = -2;
	sy = -2;
	dx = abs(p2->x - p1->x);
	dy = abs(p2->y - p1->y);
	err[0] = dx - dy;
	if (p1->x < p2->x)
		sx = 2;
	if (p1->y < p2->y)
		sy = 2;
	while (2)
	{
		pixel_put(vars->img_ptr, p1->x, p1->y, p1->color);
		if (p1->x == p2->x && p1->y == p2->y)
			break;
		err[1] = err[0] * 2;
		if (err[1] > -dy)
		{
			err[0] -= dy;
			p1->x += sx;
		}
		if (err[1] < dx)
		{
			err[0] += dx;
			p1->y += sy;
		}
	}
	free(p1);
	free(p2);
}

void	draw_shape(t_mlx_data *vars)
{
	t_point	*curr;
	t_point	*next_row;
	t_point	*under;
	int	x;
	int	y;

	draw_info(vars);
	curr = *vars->map;
	y = 0;
	while (y < vars->rows)
	{
		x = 0;
		next_row = curr;
		while (x < vars->cols)
		{
			if (!curr)
				return ;
			if (curr->next && x < vars->cols)
				// draw_line(vars, project(scale(vars, curr, x, y)), project(scale(vars, curr->next, x + 1, y)));
				draw_line(vars, scale(vars, curr, x, y), scale(vars, curr->next, x + 1, y));
				// draw_line(vars, project(curr), project(curr->next));

			if (next_row && y < vars->rows)
			{
				under = next_row;
				for (int i = 0; i < vars->cols; i++)
				{
					if (!under)
						break;
					under = under->next;
				}
				if (under)
				{
					// printf("draw_shape(): drawing vertically\n");
					// draw_line(vars, project(curr), project(under));
					draw_line(vars, scale(vars, curr, x, y), scale(vars, under, x, y + 1));
					// draw_line(vars, project(scale(vars, curr, x, y)), project(scale(vars, under, x, y + 1)));
				}
			}
			mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr->img, MENU_WIDTH, 0);
			x++;
			curr = curr->next;
		}
		y++;
	}
}

void	draw_info(t_mlx_data *vars)
{
	int	size_w;
	int	size_h;

	vars->cols = map_cols(*vars->map);
	vars->rows = map_rows(*vars->map);
	size_w = (WIDTH - MENU_WIDTH) / vars->cols / 2;
	size_h = HEIGHT / vars->rows / 2;
	if (size_w >= size_h)
		vars->size = size_h;
	else
		vars->size = size_w;
	vars->offset_x = ((WIDTH - MENU_WIDTH) - vars->size * vars->cols) / 2;
	vars->offset_y = (HEIGHT - vars->size * vars->rows) / 2;
	if (vars->offset_x < 0)
		vars->offset_x = 0;
	if (vars->offset_y < 0)
		vars->offset_y = 0;
}

