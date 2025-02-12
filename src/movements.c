/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:39:24 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:39:31 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *data)
{
	if (data->keys->pk_key == XK_Escape)
	{
		free_fdf_data(data);
		exit(0);
	}
	return (0);
}

int	cross_exit(t_fdf *data)
{
	data->keys->pk_key = XK_Escape;
	return (0);
}
