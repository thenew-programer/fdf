/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:13:59 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/12 09:14:04 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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

t_point	**parser(char *filename, t_fdf *data)
{
	t_point	**map;
	char	*line;
	char	**strs;
	int		fd;
	int		coor[2];

	map = init_map(data);
	fd = open_file(filename, data);
	line = get_next_line(fd);
	coor[1] = 0;
	while (coor[1] < data->rows && line)
	{
		strs = ft_split(line, ' ');
		coor[0] = -1;
		while (++coor[0] < data->cols)
			init_point(&map[coor[1]][coor[0]], coor,
			  ft_atoi(strs[coor[0]]), get_color(strs, coor[0]));
		free_split_strs(strs, line);
		line = get_next_line(fd);
		coor[1]++;
	}
	close(fd);
	return (map);
}
