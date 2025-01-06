/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:19:43 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/06 16:16:44 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

t_mlx_data	*init_display(void)
{
	t_mlx_data	*vars;
	t_data		img;

	vars = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!vars)
		return (NULL);
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WHIDTH, HEIGHT, TITLE);
	img.img = mlx_new_image(vars->mlx_ptr, 150, HEIGHT);
	vars->img_ptr->img = &img;
	mlx_key_hook(vars->win_ptr, keyhook, vars);
	mlx_hook(vars->win_ptr, 17, 0, close_window, vars);
	return (vars);
}
