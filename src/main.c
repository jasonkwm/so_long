/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:18:19 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/07 09:39:28 by jakoh            ###   ########.fr       */
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

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 640, "Hello world!");
	ft_assign_art(&vars);
	int i = -1;
	int j = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.tile.img, j * 64, i * 64);
			mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.wall.img, j * 64, 576);
		}
			mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.wall.img, 0, i * 64);
			mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.wall.img, i * 64, 0);
			mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.wall.img, 576, i * 64);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.cat1.img, 320, 320);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.ghost1.img, 320, 384);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.coin1.img, 384, 320);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.arts.door.img, 384, 384);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

void	ft_looping_hookers(t_vars *vars)
{
	mlx_loop_hook(vars->mlx,funct_ptr,vars);
}


void	ft_exit_program(t_vars *vars)
{
	ft_putstr_fd("K Bye.\n", 1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}
