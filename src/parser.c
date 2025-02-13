/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:13:59 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:46:40 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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

t_bool	check_map(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	char	**strs;
	int		coor[2];

	(1) && (fd = open_file(filename, data), check_file_ext(filename, data));
	line = get_next_line(fd);
	if (!line)
		die(MAP_EMPTY, data);
	strs = ft_split(line, ' ');
	coor[0] = ft_strs_len(strs);
	free_split_strs(strs, NULL);
	coor[1] = 0;
	while (line && ++coor[1] >= 0)
	{
		strs = ft_split(line, ' ');
		if (ft_strs_len(strs) != coor[0])
			return (free_split_strs(strs, line), FALSE);
		free_split_strs(strs, line);
		line = get_next_line(fd);
	}
	data->cols = coor[0];
	data->rows = coor[1];
	close(fd);
	return (TRUE);
}

t_bool	check_file_ext(char *filename, t_fdf *data)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext == filename || !ext)
		die(FILE_EXT_ERR, data);
	else if (*(ext - 1) == '/')
		die(FILE_EXT_ERR, data);
	else if (ft_strncmp(ext, EXTENSION, ft_strlen(ext)) != 0)
		die(FILE_EXT_ERR, data);
	return (TRUE);
}
