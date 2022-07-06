/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:18:19 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/06 20:27:01 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	int	i;

	i = 0;
	vars->count++;
	if (keycode == 53)
		ft_exit_program(vars);
	if (keycode == 123)
		printf("Left Key.\n");
	if (keycode == 124)
		printf("Right Key.\n");
	if (keycode == 125)
		printf("Down Key.\n");
	if (keycode == 126)
		printf("Up Key.\n");
	
	printf("i: %i\n", vars->count);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img1;
	t_data	img2;
	t_data	img3;
	t_data	img4;
	t_data	img5;
	t_data	img6;
	int size;

	size = 64;
	vars.count = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 640, "Hello world!");
	img1.img = mlx_xpm_file_to_image(vars.mlx, "resources/cat/cat1.xpm", &size, &size);
	img2.img = mlx_xpm_file_to_image(vars.mlx, "resources/coin/coin1.xpm", &size, &size);
	img3.img = mlx_xpm_file_to_image(vars.mlx, "resources/ghost/ghost1.xpm", &size, &size);
	img4.img = mlx_xpm_file_to_image(vars.mlx, "resources/door.xpm", &size, &size);
	img5.img = mlx_xpm_file_to_image(vars.mlx, "resources/wall.xpm", &size, &size);
	img6.img = mlx_xpm_file_to_image(vars.mlx,"resources/background.xpm", &size, &size);
	int i = -1;
	int j = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img6.img, j * 64, i * 64);
			mlx_put_image_to_window(vars.mlx, vars.win, img5.img, j * 64, 576);
		}
			mlx_put_image_to_window(vars.mlx, vars.win, img5.img, 0, i * 64);
			mlx_put_image_to_window(vars.mlx, vars.win, img5.img, i * 64, 0);
			mlx_put_image_to_window(vars.mlx, vars.win, img5.img, 576, i * 64);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img1.img, 320, 320);
	mlx_put_image_to_window(vars.mlx, vars.win, img2.img, 320, 384);
	mlx_put_image_to_window(vars.mlx, vars.win, img3.img, 384, 320);
	mlx_put_image_to_window(vars.mlx, vars.win, img4.img, 384, 384);
	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

void	ft_exit_program(t_vars *vars)
{
	ft_putstr_fd("Exit program.\n", 1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}