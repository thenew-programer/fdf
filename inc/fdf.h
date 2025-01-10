/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:20:11 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/10 10:42:21 by ybouryal         ###   ########.fr       */
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

# define TITLE		"FdF"
# define WIDTH		800
# define HEIGHT		800	
# define MENU_WIDTH	20
# define ANGLE		30

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
	int		rows;
	int		cols;
	int		size;
	int		offset_x;
	int		offset_y;
}	t_mlx_data;

/* -----------------IO----------------- */
int	open_file(char *filename);

/* ----------------Utils--------------- */
void	free_strs(char **strs);
t_point	*scale(t_mlx_data *vars, t_point *p, int x, int y);

/* -----------------map---------------- */
t_point	*point_new(int x, int y, int z, int color);
void	pointadd_back(t_point **head, t_point *new_node);
int		map_size(t_point *map);
void	map_free(t_point **map);
t_point	*point_last(t_point *map);
void	map_print(t_point *map);
int		map_cols(t_point *map);
int		map_rows(t_point *map);

/* ---------------parser-------------- */
void 	construct_map(t_point **map, char **strs, int y);
t_point *parser(int ac, char **av);

/* ---------------hooks--------------- */
int		keyhook(int keycode, t_mlx_data *data);
int		close_window(t_mlx_data *data);

/* --------------display-------------- */
t_mlx_data	*init_display(void);
void		pixel_put(t_data *data, int x, int y, int color);

/* ---------------draw---------------- */
void	draw_info(t_mlx_data *vars);
void	draw(t_mlx_data *vars, t_point *p);
void	draw_shape(t_mlx_data *vars);

/* -----------projections------------- */
void	isometric_projection(t_point *p);

#endif /* FDF_H */
