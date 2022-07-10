/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:22:22 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/09 11:49:56 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_assign_utils(t_vars *vars);
static void	ft_assign_cat(t_vars *vars);
static void	ft_assign_ghost(t_vars *vars);

void	ft_assign_art(t_vars *vars)
{
	ft_assign_utils(vars);
	ft_assign_cat(vars);
	ft_assign_ghost(vars);
}

static void	ft_assign_utils(t_vars *vars)
{
	int	s;

	s = 64;
	vars->arts.tile.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/tile.xpm", &s, &s);
	vars->arts.exit.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/door.xpm", &s, &s);
	vars->arts.wall.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/wall.xpm", &s, &s);
	vars->arts.coin1.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/coin/coin1.xpm", &s, &s);
	vars->arts.coin2.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/coin/coin2.xpm", &s, &s);
	vars->arts.coin3.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/coin/coin3.xpm", &s, &s);
	vars->arts.coin4.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/coin/coin4.xpm", &s, &s);
	vars->arts.coin5.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/coin/coin5.xpm", &s, &s);
}

static void	ft_assign_cat(t_vars *vars)
{
	int	s;

	s = 64;
	vars->arts.cat1.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/cat/cat1.xpm", &s, &s);
	vars->arts.cat2.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/cat/cat2.xpm", &s, &s);
	vars->arts.cat3.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/cat/cat3.xpm", &s, &s);
	vars->arts.cat4.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/cat/cat4.xpm", &s, &s);
	vars->arts.cat5.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/cat/cat5.xpm", &s, &s);
}

static void	ft_assign_ghost(t_vars *vars)
{
	int	s;

	s = 64;
	vars->arts.ghost1.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/ghost/ghost1.xpm", &s, &s);
	vars->arts.ghost2.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/ghost/ghost2.xpm", &s, &s);
	vars->arts.ghost3.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/ghost/ghost3.xpm", &s, &s);
	vars->arts.ghost4.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/ghost/ghost4.xpm", &s, &s);
	vars->arts.ghost5.img = mlx_xpm_file_to_image(vars->mlx,
			"resources/ghost/ghost5.xpm", &s, &s);
}
