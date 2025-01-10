/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:19:43 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/07 10:11:57 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <errno.h>

static void	display_error(t_mlx_data *vars)
{
	errno = ENOMEM;
	perror("fdf: ");
	if (vars)
	{
		if (vars->img_ptr)
		{
			if (vars->img_ptr->img)
				mlx_destroy_image(vars->mlx_ptr, vars->img_ptr->img);
			free(vars->img_ptr);
		}
		if (vars->win_ptr)
			mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		if (vars->mlx_ptr)
			mlx_destroy_display(vars->mlx_ptr);
		if (vars->mlx_ptr)
			free(vars->mlx_ptr);
		free(vars);
	}
}

static void	init_vars(t_mlx_data *vars)
{
	vars->img_ptr = NULL;
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->map = NULL;
}

t_mlx_data	*init_display(void)
{
	t_mlx_data	*vars;

	vars = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!vars)
		return (display_error(vars), NULL);
	init_vars(vars);
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (display_error(vars), NULL);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!vars->win_ptr)
		return (display_error(vars), NULL);
	vars->img_ptr = (t_data *)malloc(sizeof(t_data));
	if (!vars->img_ptr)
		return (display_error(vars), NULL);
	vars->img_ptr->img = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	if (!vars->img_ptr->img)
		return (display_error(vars), NULL);
	vars->img_ptr->addr = mlx_get_data_addr(vars->img_ptr->img,
										 &vars->img_ptr->bits_per_pixel,
										 &vars->img_ptr->line_length,
										 &vars->img_ptr->endian);
	mlx_key_hook(vars->win_ptr, keyhook, vars);
	mlx_hook(vars->win_ptr, 17, 0, close_window, vars);
	return (vars);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}
