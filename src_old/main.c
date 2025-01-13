/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:38 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/11 18:38:03 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_point		*map;
	t_fdf	*vars;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf <filename>", 2);
		return (1);
	}
	map = parser(ac, av);
	if (map == NULL)
		return (1);
	map_print(map);
	vars = init_display();
	if (!vars)
		return (map_free(&map), 1);
	vars->map = &map;
	draw_shape(vars);
	mlx_loop(vars->mlx_ptr);
	map_free(&map);
	return (0);
}
