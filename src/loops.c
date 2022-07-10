/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:50:17 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 11:14:19 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_looping_hookers(t_vars *vars)
{
	static	int	frame;

	frame++;
	ft_print_static(vars);
	if (frame == 1)
		ft_image_god(vars, vars->arts.cat1, vars->arts.ghost1, vars->arts.coin1);
	else if (frame <= FRAMES)
		ft_image_god(vars, vars->arts.cat2, vars->arts.ghost2, vars->arts.coin2);
	else if (frame <= FRAMES * 2)
		ft_image_god(vars, vars->arts.cat3, vars->arts.ghost3, vars->arts.coin3);
	else if (frame <= FRAMES * 3)
		ft_image_god(vars, vars->arts.cat4, vars->arts.ghost4, vars->arts.coin4);
	else if (frame <= FRAMES * 4)
		ft_image_god(vars, vars->arts.cat5, vars->arts.ghost5, vars->arts.coin5);
	else
		frame = 0;
	return 0;
}

void	ft_image_god(t_vars *vars, t_img cat, t_img ghost, t_img coin)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.grid[++i] != NULL)
	{
		j = -1;
		while (vars->map.grid[i][++j] != 0)
		{
			if (vars->map.grid[i][j] == 'C')
				ft_single_frame(vars, coin, j, i);
			if (vars->map.grid[i][j] == 'P')
				ft_single_frame(vars, cat, j, i);
			if (vars->map.grid[i][j] == 'L')
				ft_single_frame(vars, ghost, j, i);
		}
	}
}
