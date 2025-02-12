/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_help_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:57:54 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:50:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	header_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin * 2, 25,
		MENU_TEXT, "*******************");
	mlx_string_put(mlx, win, l_margin * 2 + 5,
		40, MENU_TEXT, "File De Fer - FDF");
	mlx_string_put(mlx, win, l_margin * 2 + 6, 40,
		MENU_TEXT, "File De Fer - FDF");
	mlx_string_put(mlx, win, l_margin * 2, 60,
		MENU_TEXT, "*******************");
}

void	rotate_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 40,
		MENU_TEXT, "Rotation");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 40,
		MENU_TEXT, "Rotation");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 60,
		MENU_TEXT, "- X-Axis: <x>/<S-x>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 80,
		MENU_TEXT, "- Y-Axis: <y>/<S-y>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 100,
		MENU_TEXT, "- Z-Axis: <z>/<S-z>");
}

void	project_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 150,
		MENU_TEXT, "Projection");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 150,
		MENU_TEXT, "Projection");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 170,
		MENU_TEXT, "- Isometric: <i>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 190,
		MENU_TEXT, "- Parallel:  <p>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 210,
		MENU_TEXT, "- Conic:     <c>");
}

void	translate_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 260,
		MENU_TEXT, "Translation");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 260,
		MENU_TEXT, "Translation");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 280,
		MENU_TEXT, "- Up:    <w>/<keyup>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 300,
		MENU_TEXT, "- Down:  <s>/<keydown");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 320,
		MENU_TEXT, "- Right: <a>/<keyright>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 340,
		MENU_TEXT, "- Left:  <d>/<keyleft>");
}
