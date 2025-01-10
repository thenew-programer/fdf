/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:38 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/10 10:58:50 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_point		*map;
	t_mlx_data	*vars;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf <filename>", 2);
		return (1);
	}
	map = parser(ac, av);
	if (map == NULL)
		return (1);
	map_print(map);
	vars = init_display();
	if (!vars)
		return (map_free(&map), 1);
	vars->map = &map;
	draw_shape(vars);
	mlx_loop(vars->mlx_ptr);
	map_free(&map);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
//
// #define WIN_WIDTH 800
// #define WIN_HEIGHT 600
//
// // Matrix dimensions
// #define ROWS 5
// #define COLS 5
//
// // Matrix to draw (1 for filled square, 0 for empty space)
// int matrix[ROWS][COLS] = {
//     {1, 0, 1, 0, 1},
//     {0, 1, 0, 1, 0},
//     {1, 1, 1, 1, 1},
//     {0, 1, 0, 1, 0},
//     {1, 0, 1, 0, 1}
// };
//
// // Function to draw the border of a square
// void draw_square_border(void *mlx, void *win, int x, int y, int size, int color)
// {
//     // Draw top and bottom borders
//     for (int i = 0; i < size; i++)
//     {
//         mlx_pixel_put(mlx, win, x + i, y, color);               // Top border
//         mlx_pixel_put(mlx, win, x + i, y + size - 1, color);   // Bottom border
//     }
//
//     // Draw left and right borders
//     for (int j = 0; j < size; j++)
//     {
//         mlx_pixel_put(mlx, win, x, y + j, color);              // Left border
//         mlx_pixel_put(mlx, win, x + size - 1, y + j, color);  // Right border
//     }
// }
//
// int main()
// {
//     void *mlx;
//     void *win;
//
//     // Initialize MiniLibX
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         fprintf(stderr, "Failed to initialize MiniLibX\n");
//         return (1);
//     }
//
//     // Create a window
//     win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Dynamic Matrix with Dynamic Spacing");
//     if (!win)
//     {
//         fprintf(stderr, "Failed to create window\n");
//         return (1);
//     }
//
//     // Calculate square size and spacing
//     int square_size_width = WIN_WIDTH / COLS / 2;
//     int square_size_height = WIN_HEIGHT / ROWS / 2;
//     int square_size = (square_size_width < square_size_height) ? square_size_width : square_size_height;
//
//     // int spacing = square_size / 5;
// 	int	spacing = 0;
//
//     // Calculate matrix dimensions
//     int matrix_width = (COLS * square_size);
//     int matrix_height = (ROWS * square_size);
//
//     // Calculate offsets to center the matrix
//     int offset_x = (WIN_WIDTH - matrix_width) / 2;
//     int offset_y = (WIN_HEIGHT - matrix_height) / 2;
//
//     // Draw the matrix
//     for (int row = 0; row < ROWS; row++)
//     {
//         for (int col = 0; col < COLS; col++)
//         {
// 			int x = offset_x + col * (square_size + spacing);
// 			int y = offset_y + row * (square_size + spacing);
// 			draw_square_border(mlx, win, x, y, square_size, 0x00FF00); // Green border
//         }
//     }
//
//     // Run the event loop
//     mlx_loop(mlx);
//
//     return (0);
// }
