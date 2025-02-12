/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:17:48 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:18:58 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char **strs, int x)
{
	int		color;
	int		i;
	char	**tab;

	color = 0;
	tab = ft_split(strs[x], ',');
	if (ft_strs_len(tab) <= 1)
		return (free_split_strs(tab, NULL), TEXT);
	i = 0;
	if (tab[1][i] == '0' && tab[1][i + 1] == 'x')
		i++;
	while (tab[1][++i])
	{
		if (tab[1][i] >= '0' && tab[1][i] <= '9')
			color = (color << 4) | (tab[1][i] - '0');
		else if (tab[1][i] >= 'A' && tab[1][i] <= 'Z')
			color = (color << 4) | (tab[1][i] - 'A' + 10);
		else if (tab[1][i] >= 'a' && tab[1][i] <= 'z')
			color = (color << 4) | (tab[1][i] - 'a' + 10);
		else
			break ;
	}
	free_split_strs(tab, NULL);
	return (color);
}
