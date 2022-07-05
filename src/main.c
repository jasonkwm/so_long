/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:18:19 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/05 14:27:40 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img1;

	int x;
	int y;

	x = 32;
	y = 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img1.img = mlx_xpm_file_to_image(mlx, "cat_1.xpm", &x, &y);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length,
								&img1.endian);

	mlx_put_image_to_window(mlx, mlx_win, img1.img, 0, 0);
	mlx_loop(mlx);
}