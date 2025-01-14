/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:48:24 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 12:04:08 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**init_map(t_fdf *data)
{
	t_point	**map;
	int		y;

	map = (t_point **)malloc(sizeof(t_point *) * data->rows);
	if (!map)
		die(MALLOC_ERR, data);
	y = 0;
	data->map = map;
	while (y < data->rows)
	{
		map[y] = (t_point *)malloc(sizeof(t_point) * data->cols);
		if (!map[y])
		{
			data->rows = y;
			die(MALLOC_ERR, data);
		}
		y++;
	}
	return (map);
}

void	free_map(t_point **map, t_fdf *data)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < data->rows)
	{
		free(map[y]);
		y++;
	}
	free(map);
	data->map = NULL;
}

void	init_point(t_point *p, int *coor, int z, int color)
{
	p->x = coor[0];
	p->y = coor[1];
	p->z = z;
	p->color = color;
}
