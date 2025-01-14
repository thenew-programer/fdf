/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:57:45 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 10:33:30 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "colors.h"
# include "err_msg.h"
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>

# define WIDTH		1300
# define HEIGHT		700
# define MENU_WIDTH	WIDTH / 6
# define PI			22.0 / 7.0

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL,
	CONIC
}	t_projection;

typedef enum e_xevent
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17,
}	t_xevent;

typedef struct s_img_data
{
	char	*addr;
	void	*img;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_menu_data
{
	t_img_data	*img_ptr;
	int			top_margin;
	int			left_margin;
}	t_menu;

typedef struct s_keys
{
	int	PK_shift;
	int	PK_ctrl;
	int	PK_key;
}	t_keys;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_screen
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	double			angle;
	float			z_div;
	int				offset_x;
	int				offset_y;
}	t_screen;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	*img_ptr;
	t_screen	*screen;
	t_keys		*keys;
	t_menu		*menu;
	t_point		**map;
	char		*w_title;
	int			cols;
	int			rows;
}	t_fdf;

/* Functions Prototype */

/* ------------------------------err.c-------------------------------------- */
void	die(char *err, t_fdf *data);

/* ------------------------------utils.c------------------------------------ */
void	free_split_strs(char **strs, char *line);
t_bool	check_file_ext(char *filename, t_fdf *data);
t_bool	check_map(char *filename, t_fdf *data);
int		open_file(char *filename, t_fdf *data);
int		ft_strs_len(char **strs);
int		min(int x, int y);

/* ------------------------------map.c-------------------------------------- */
t_point	**init_map(t_fdf *data);
void	free_map(t_point **map, t_fdf *data);
void	init_point(t_point *p, int *coor, int z, int color);

/* -----------------------------parser.c------------------------------------ */
t_point	**parser(char *filename, t_fdf *data);

/* ----------------------------graphics.c----------------------------------- */
void	free_graphics(t_fdf *data);
void	init_graphics(t_fdf *data);

/* ------------------------------hooks.c------------------------------------ */
int		close_window(t_fdf *data);
int		keyhook(int keycode, t_fdf *data);
int		key_press(int keycode, t_fdf *data);
int		key_release(int keycode, t_fdf *data);
int		mouse_exit(t_fdf *data);
int		mousehook(int button, int x, int y, t_fdf *data);

/* ------------------------------main.c--------------------------------------*/
void	free_fdf_data(t_fdf *data);

/* ------------------------------draw.c--------------------------------------*/
void	pixel_put(t_img_data *data, int x, int y, int color);
void	draw(t_fdf *data);
void	draw_menu(t_fdf *data);

/* ----------------------------project.c-------------------------------------*/
t_point	project(t_fdf *data, t_point p);


/* ----------------------------renderer.c------------------------------------*/
int		render(t_fdf *data);

/* ----------------------------geometry.c------------------------------------*/
void	rotate(t_fdf *data);
void	translate(t_fdf *data);
void	projection(t_fdf *data);
void	zoom(t_fdf *data);
void	flatten(t_fdf *data);
void	reset(t_fdf *data);
int		close_window(t_fdf *data);

#endif /* FDF_H */
