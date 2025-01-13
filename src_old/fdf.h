/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:20:11 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/11 18:39:58 by ybouryal         ###   ########.fr       */
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
# include <errno.h>
# include "libft.h"
# include "mlx.h"
# include "error_msg.h"

# define TITLE		"FdF"
# define WIDTH		1920
# define HEIGHT		1080
# define MENU_WIDTH	220
# define PI			3.141592653589793
# define ISO_ANGLE	PI / 6.0

typedef enum e_bool
{
	FALSE,
	TRUE	
}	t_bool;

typedef enum e_projection
{
	ISOMORPHIC,
	PARALLEL,
	CONIC
}	t_projection;

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

typedef struct s_point t_vector;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*img_ptr;
	t_point		**map;
	t_vector	***vector;
	int			rows;
	int			cols;
	int			size;
	int			offset_x;
	int			offset_y;
}	t_fdf;

/* -----------------IO----------------- */
int	open_file(char *filename);

/* ----------------Utils--------------- */
void	free_strs(char **strs);
t_point	*scale(t_fdf *vars, t_point *p, int x, int y);

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
int		construct_map(t_point **map, char **strs, int y, int old_x);
t_point *parser(int ac, char **av);

/* ---------------hooks--------------- */
int		keyhook(int keycode, t_fdf *data);
int		close_window(t_fdf *data);

/* --------------display-------------- */
t_fdf	*init_display(void);
void	pixel_put(t_data *data, int x, int y, int color);

/* ---------------draw---------------- */
void	draw_info(t_fdf *vars);
void	draw(t_fdf *vars, t_point *p);
void	draw_shape(t_fdf *vars);

/* -----------projections------------- */
void	isometric_projection(t_point *p);

#endif /* FDF_H */
