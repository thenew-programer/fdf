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
#include "libft.h"

int	parse_color(char *str)
{
	int		result;
	char	**strs;
	int		i;

	result = 0;
	if (!str)
		return (0x00FFFFFF);
	strs = ft_split(str, ',');
	if (!strs || !strs[1])
		return (free_strs(strs), 0x00FFFFFF);
	if (strs[1][0] != '0' && strs[1][1] != 'x')
		return (free_strs(strs), 0x00FFFFFF);
	i = 1;
	while (strs[1][++i])
	{
		if (strs[1][i] >= '0' && strs[1][i] <= '9')
			result = (result << 4 ) | (strs[1][i] - '0');
		else if (strs[1][i] >= 'A' && strs[1][i] <= 'F')
			result = (result << 4 ) | (strs[1][i] - 'A' + 10);
		else if (strs[1][i] >= 'a' && strs[1][i] <= 'f')
			result = (result << 4 ) | (strs[1][i] - 'a' + 10);
		else
			return (free_strs(strs), -1);
	}
	return (free_strs(strs), result);
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
			ft_putendl_fd("fdf: map khasra color machi hwa hadak", 2);
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
// int main(void)
// {
//     char *example1 = "10,0x0000ff00";
//     char *example2 = "0,0x000FAB12";
//     char *example3 = "42,0xinvalid";
//     char *example4 = "hello,0xx";
//
//     printf("Parsed color 1: %#010X\n", parse_color(example1)); // 0x00FF00
//     printf("Parsed color 2: %#010X\n", parse_color(example2)); // 0x0FAB12
//     printf("Parsed color 3: %#010X\n", parse_color(example3)); // 0xFFFFFF
//     printf("Parsed color 4: %#010X\n", parse_color(example4)); // 0xFFFFFF
//
//     return 0;
// }
