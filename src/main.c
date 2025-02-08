/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:00:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:27:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		die(MALLOC_ERR, data);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->screen = NULL;
	data->menu = NULL;
	data->map = NULL;
	data->keys = NULL;
	data->w_title = NULL;
	data->cols = 0;
	data->rows = 0;
	return (data);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	data = init_fdf();
	if (ac < 2)
		die(USAGE_ERR, data);
	if (!check_map(av[1], data))
		die(MAP_FORMAT_ERR, data);
	data->map = parser(av[1], data);
	data->w_title = ft_strjoin("Fdf - ", av[1]);
	init_graphics(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
