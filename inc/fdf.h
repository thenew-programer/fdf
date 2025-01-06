/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:20:11 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/04 11:09:57 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	char			color[11];
	struct s_point	*next;
}	t_point;

/* -----------------IO----------------- */
int	open_file(char *filename);

/* ----------------Utils--------------- */
void	free_strs(char **strs);

/* -----------------map---------------- */
t_point	*point_new(int x, int y, int z, char *color);
void	pointadd_back(t_point **head, t_point *new_node);
int		map_size(t_point *map);
void	map_free(t_point **map);
t_point	*point_last(t_point *map);
void	map_print(t_point *map);

/* ---------------parser-------------- */
void construct_map(t_point **map, char **strs, int y);
t_point *parser(int ac, char **av);

#endif /* FDF_H */
