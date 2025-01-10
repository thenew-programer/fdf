/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:35:01 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/04 10:40:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

t_point	*scale(t_mlx_data *vars, t_point *p, int x, int y)
{
	t_point	*scaled;

	scaled = point_new(p->x, p->y, p->z, p->color);
	scaled->x = vars->offset_x + x * vars->size;
	scaled->y = vars->offset_y + y * vars->size;
	return (scaled);
}
