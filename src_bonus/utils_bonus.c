/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:13:41 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:45:45 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_strs_len(char **strs)
{
	int	i;

	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	open_file(char *filename, t_fdf *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
		die(FILE_ERR, data);
	return (fd);
}

int	min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}
