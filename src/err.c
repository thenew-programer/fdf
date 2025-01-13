/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:14:05 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 09:14:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	die(char *err, t_fdf *data)
{
	ft_putstr_fd("Fdf: ", 2);
	if (errno == 0)
		ft_putendl_fd(err, 2);
	else
		perror(err);
	free_fdf_data(data);
	exit(1);
}
