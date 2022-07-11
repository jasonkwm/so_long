/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:29:14 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 16:31:53 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// to shorten code
void	ft_change_pos(t_vars *vars, int x, int y, char c)
{
	if (c == 'P')
	{
		vars->hero[0] += y;
		vars->hero[1] += x;
	}
	if (c == 'L')
	{
		vars->enemy[0] += y;
		vars->enemy[1] += x;
	}
}

// puts player to map
void	ft_put_hero(t_vars *vars, int x, int y)
{
	vars->map.grid[vars->hero[0]][vars->hero[1]] = '0';
	vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] = 'P';
	ft_change_pos(vars, x, y, 'P');
}

// Enemy pushes coin
// if hero infront hero will get the coin
// if not space then dont push coin
void	ft_push_coin(t_vars *vars, int x, int y)
{
	int	i;

	i = 1;
	while (vars->map.grid[vars->enemy[0] + (y * i)]
		[vars->enemy[1] + (x * i)] == 'C')
		i++;
	if (vars->map.grid[vars->enemy[0] + (y * i)]
		[vars->enemy[1] + (x * i)] == '0')
	{
		vars->map.grid[vars->enemy[0]][vars->enemy[1]] = '0';
		vars->map.grid[vars->enemy[0] + (y * i)]
		[vars->enemy[1] + (x * i)] = 'C';
		vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] = 'L';
		ft_change_pos(vars, x, y, 'L');
	}
	if (vars->map.grid[vars->enemy[0] + (y * i)]
		[vars->enemy[1] + (x * i)] == 'P')
	{
		vars->coin_count -= 1;
		vars->map.grid[vars->enemy[0]][vars->enemy[1]] = '0';
		vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] = 'L';
		ft_change_pos(vars, x, y, 'L');
	}
}
