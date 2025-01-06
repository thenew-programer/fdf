/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:20:11 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/06 16:17:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>
# include "libft.h"
# include "mlx.h"

# define TITLE "FdF"
# define HEIGHT	1920
# define WHIDTH 1080
# define MENU_WHIDTH 250

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_data	*next;
}	t_data;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}	t_point;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img_ptr;
	t_point	**map;
}	t_mlx_data;

/* -----------------IO----------------- */
int	open_file(char *filename);

/* ----------------Utils--------------- */
void	free_strs(char **strs);

/* -----------------map---------------- */
t_point	*point_new(int x, int y, int z, int color);
void	pointadd_back(t_point **head, t_point *new_node);
int		map_size(t_point *map);
void	map_free(t_point **map);
t_point	*point_last(t_point *map);
void	map_print(t_point *map);

/* ---------------parser-------------- */
void construct_map(t_point **map, char **strs, int y);
t_point *parser(int ac, char **av);

/* ---------------hooks-------------- */
int	keyhook(int keycode, t_mlx_data *data);
int	close_window(t_mlx_data *data);
#endif /* FDF_H */
