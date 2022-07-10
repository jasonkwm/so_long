/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:42:53 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/09 12:46:37 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_temp_walls(t_vars *vars)
{
	int i = -1;
	int j = 0;
	
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.tile.img, j * 64, i * 64);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, j * 64, 576);
		}
			mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, 0, i * 64);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, i * 64, 0);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, 576, i * 64);
	}
}

void	ft_temp_count(t_vars *vars)
{
	printf("0: %i\n", ft_count_char(vars->map.grid, '0'));
	printf("1: %i\n", ft_count_char(vars->map.grid, '1'));
	printf("C: %i\n", ft_count_char(vars->map.grid, 'C'));
	printf("E: %i\n", ft_count_char(vars->map.grid, 'E'));
	printf("P: %i\n", ft_count_char(vars->map.grid, 'P'));
	printf("L: %i\n", ft_count_char(vars->map.grid, 'L'));
}
