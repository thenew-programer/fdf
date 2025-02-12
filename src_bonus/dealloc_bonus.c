/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:26:22 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:44:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_graphics(t_fdf *data)
{
	if (data)
	{
		if (data->menu)
		{
			if (data->menu->img_ptr)
			{
				if (data->menu->img_ptr->img)
					mlx_destroy_image(data->mlx_ptr, data->menu->img_ptr->img);
				free(data->menu->img_ptr);
			}
		}
		if (data->img_ptr)
		{
			if (data->img_ptr->img)
				mlx_destroy_image(data->mlx_ptr, data->img_ptr->img);
			free(data->img_ptr);
		}
		if (data->win_ptr)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
		if (data->mlx_ptr)
			mlx_destroy_display(data->mlx_ptr);
	}
}

void	free_fdf_data(t_fdf *data)
{
	free_graphics(data);
	if (data)
	{
		if (data->mlx_ptr)
			free(data->mlx_ptr);
		if (data->win_ptr)
			free(data->win_ptr);
		if (data->w_title)
			free(data->w_title);
		if (data->map)
			free_map(data->map, data);
		if (data->screen)
			free(data->screen);
		if (data->keys)
			free(data->keys);
		if (data->menu)
			free(data->menu);
		free(data);
	}
}

void	free_split_strs(char **strs, char *line)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	if (line)
		free(line);
}
