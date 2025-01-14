/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:47:45 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/14 21:51:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 390, MENU_TEXT, "Zoom");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 390, MENU_TEXT, "Zoom");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 410,
		MENU_TEXT, "- In:  <+>/<S-=>");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 430,
		MENU_TEXT, "- Out: <->");
}

void	reset_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 560, MENU_TEXT, "Reset");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 560, MENU_TEXT, "Reset");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 580,
		MENU_TEXT, "- Reset to default: <r>");
}

void	exit_help(t_fdf *data)
{
	void	*mlx;
	void	*win;
	int		l_margin;
	int		t_margin;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	t_margin = 60;
	l_margin = data->menu->left_margin;
	mlx_string_put(mlx, win, l_margin, t_margin + 610, MENU_TEXT, "Exit");
	mlx_string_put(mlx, win, l_margin + 1, t_margin + 610, MENU_TEXT, "Exit");
	mlx_string_put(mlx, win, l_margin + 15, t_margin + 630,
		MENU_TEXT, "- Quit: <ESC>");
}
