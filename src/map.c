/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:41:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/07 10:22:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*point_new(int x, int y, int z, int color)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	p->color = color;
	p->next = NULL;
	return (p);
}

void	pointadd_back(t_point **head, t_point *new_node)
{
	t_point	*last;

	last = point_last(*head);
	if (!last)
		(*head) = new_node;
	else
		last->next = new_node;
}

int	map_size(t_point *map)
{
	int	size;

	size = 0;
	while (map != NULL)
	{
		map = map->next;
		size++;
	}
	return (size);
}

void	map_free(t_point **map)
{
	t_point	*curr;
	t_point	*next;

	curr = *map;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*map = NULL;
}

t_point	*point_last(t_point *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

void	map_print(t_point *map)
{
	if (!map)
		return ;
	while (map)
	{
		printf("%2d:%d,%d", map->z, map->x, map->y);
		if (map->next == NULL)
		{
			printf("\n");
			return ;
		}
		if (map->next->y != map->y)
			printf("\n");
		else
			printf(" ");
		map = map->next;
	}
}

int	map_cols(t_point *map)
{
	int	x;

	x = 0;
	while (map)
	{
		if (!map->next || map->next->y != map->y)
			return (x);
		x++;
		map = map->next;
	}
	return (-1);
}

int	map_rows(t_point *map)
{
	int	y;

	y = 0;
	while (map)
	{
		if (!map->next)
			return (++y);
		if (map->next->y != map->y)
			y++;
		map = map->next;
	}
	return (-1);
}

// int main(int ac, char **av)
// {
// 	t_point	*map;
// 	int		x;
// 	int		y;
//
// 	map = parser(ac, av);
// 	if (map == NULL)
// 		return (1);
// 	map_print(map);
// 	x = map_x(map);
// 	y = map_y(map);
// 	printf("x = %d - y = %d\n", x, y);
// 	map_free(&map);
// }
