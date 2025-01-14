/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:00:58 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/13 11:19:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	free_fdf_data(t_fdf *data)
{
	free_graphics(data);
	if (data)
	{
		if (data->mlx_ptr)
			free(data->mlx_ptr), data->mlx_ptr = NULL;
		if (data->win_ptr)
			free(data->win_ptr), data->win_ptr = NULL;
		if (data->w_title)
			free(data->w_title), data->w_title = NULL;
		if (data->map)
			free_map(data->map, data);
		if (data->screen)
			free(data->screen), data->screen = NULL;
		if (data->keys)
			free(data->keys), data->keys = NULL;
		free(data);
	}
}

t_fdf	*init(void)
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

	data = init();
	if (ac < 2)
		die(USAGE_ERR, data);
	check_file_ext(av[1], data);
	if (!check_map(av[1], data))
		die(MAP_FORMAT_ERR, data);
	data->map = parser(av[1], data);
	data->w_title = ft_strjoin("Fdf - ", av[1]);
	printf("map in file %s is valid\n", data->w_title);
	printf("Map Width = %d\nMap Height = %d\n", data->cols, data->rows);
	init_graphics(data);
	draw_menu(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
