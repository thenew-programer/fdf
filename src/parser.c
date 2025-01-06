/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:27:10 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/04 11:08:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_color(char *str)
{
	int		result;
	char	*hex;
	char	*pos;
	int		i;

	result = 0;
	hex = "0123456789ABCDEF";
	if (!str)
		return (0x00FFFFFF);
	while (ft_isdigit(*str) && *str)
		str++;
	if (*str != ',')
		return (0x00FFFFFF);
	if (*(++str) == '0' && *(str + 1) == 'x')
		str += 2;
	i = 8;
	while (--i >= 0)
	{
		pos = ft_strchr(hex, *str);
		if (!pos || !*str)
			return (-1);
		result = (result << 4 ) | (pos - hex);
		str++;
	}
	return (result);
}

void	construct_map(t_point **map, char **strs, int y)
{
	int		x;
	int		z;
	int		color;
	t_point	*point;

	x = -1;
	while (strs[++x])
	{
		z = ft_atoi(strs[x]);
		color = parse_color(strs[x]);
		if (color == -1)
		{
			perror("fdf: map khasra\n");
			map_free(map);
			exit(1);
		}
		point = point_new(x, y, z, color);
		if (!point)
		{
			perror("fdf: malloc failed - ");
			map_free(map);
			exit(1);
		}
		pointadd_back(map, point);
	}
}

t_point	*parser(int ac, char **av)
{
	int		fd;
	t_point	*map;
	char	**strs;
	char	*str;
	int		y;

	map = NULL;
	fd = open_file(av[ac - 1]);
	y = 0;
	str = get_next_line(fd);
	while (str)
	{
		strs = ft_split(str, ' ');
		construct_map(&map, strs, y);
		free(str);
		free_strs(strs);
		y++;
		str = get_next_line(fd);
	}
	return (map);
}
// int main()
// {
// 	char	*str;
// 	int		color;
//
// 	str = "10,0x00FF00FF";
// 	color = parse_color(str);
// 	if (color == 0x00FF00FF)
// 		printf("color = %#010X - OK\n", color);
// 	if (color == 0x00FFFFFF)
// 		printf("color = %#010X - KO\n", color);
// 	if (color == -1)
// 		printf("An error ocurred\n");
// }
