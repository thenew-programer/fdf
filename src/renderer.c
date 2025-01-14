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

int	render(t_fdf *data)
{
	zoom(data);
	rotate(data);
	translate(data);
	projection(data);
	flatten(data);
	reset(data);
	close_window(data);
	draw(data);
	return (0);
}
