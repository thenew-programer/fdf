/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:31:26 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/05 22:25:08 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_error(const char *err, int count, ...)
{
	va_list	args;
	int	i;

	perror(err);
	if (count <= 0)
		return ;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		i++;
	}

	va_end(args);
}
