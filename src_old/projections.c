/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:40:26 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/10 10:41:09 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_point *p)
{
	int	prev_x;
	int	prev_y;

	if (!p)
		return ;
	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(ISO_ANGLE) + prev_y * cos(ISO_ANGLE + 2) + p->z * cos(ISO_ANGLE - 2);
	p->y = prev_x * sin(ISO_ANGLE) + prev_y * sin(ISO_ANGLE + 2) + p->z * sin(ISO_ANGLE - 2);
	// p->x = (prev_x - prev_y) * cos(ISO_ANGLE);
	// p->y = (prev_x + prev_y) * sin(ISO_ANGLE) - p->z;
}
