/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:41:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/04 11:08:11 by ybouryal         ###   ########.fr       */
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
		printf("%2d", map->z);
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

// int main()
// {
// 	t_point	*map;
//
// 	pointadd_back(&map, point_new(0, 0, 0, NULL));
// 	pointadd_back(&map, point_new(1, 0, 0, NULL));
// 	pointadd_back(&map, point_new(0, 1, 0, NULL));
// 	pointadd_back(&map, point_new(1, 1, 1, NULL));
// 	map_print(map);
// 	map_free(&map);
// }
