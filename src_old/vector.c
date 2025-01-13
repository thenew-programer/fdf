/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:01:38 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/11 16:08:42 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_to_vector(t_point *map)
{
	int	w;
	int	h;
	int	x;
	int	y;
	t_vector	***vector;

	w = map_cols(map);
	h = map_rows(map);
	y = 0;

	vector = (t_vector ***)malloc(sizeof(t_vector **) * h);
	while (y < h)
	{
		x = 0;
		vector[y] = (t_vector **)malloc(sizeof(t_vector*) * w);
		while (x < w)
		{
			vector[y][x] = point_new(map->x, map->y, map->z, map->color);
			map = map->next;
			x++;
		}
		y++;
	}
}
