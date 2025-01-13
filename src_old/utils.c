/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:35:01 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/11 18:38:23 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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

t_point	*scale(t_fdf *vars, t_point *p, int x, int y)
{
	t_point	*scaled;

	scaled = point_new(p->x, p->y, p->z, p->color);
	scaled->x = vars->offset_x + x * vars->size;
	scaled->y = vars->offset_y + y * vars->size;
	scaled->z *= vars->size;
	return (scaled);
}

void	die(char *err)
{
	ft_putstr_fd("Fdf: ", 2);
	if (errno == 0)
		ft_putendl_fd(err, 2);
	else
		perror(err);
	exit(1);
}

t_bool	check_file_ext(char *filename)
{
	char	**strs;
	int		i;

	strs = ft_split(filename, '.');
	if (!strs || !*strs)
		return (FALSE);
	i = 0;
	if (i + 1 == 1)
		return (FALSE);

	return (TRUE);
}
