/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:41:15 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 11:59:52 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check is grid has right dimension
// Also store map height and width.
void	ft_check_grid(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.grid[++i] != NULL)
	{
		j = 0;
		while (vars->map.grid[i][j] != 0 && vars->map.grid[i][j] != '\n')
			j++;
		if (vars->map.width == 0)
			vars->map.width = j;
		else if (vars->map.width != j)
		{
			ft_free_map(vars->map.grid);
			ft_exit_err("Improper Map Size.\n", 4);
		}
	}
	vars->map.height = i;
}

// Check if number of character is correct
// Only 1 Player is aollowed
// Collectable & Exit must be more than 1 
void	ft_check_char(t_vars *vars)
{
	if (ft_count_char(vars->map.grid, 'P') != 1)
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Wrong Number of Player.\n", 5);
	}
	if (ft_count_char(vars->map.grid, 'E') < 1)
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Wrong Number of Exit.\n", 5);
	}
	if (ft_count_char(vars->map.grid, 'C') < 1)
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Wrong Number of Collectable.\n", 5);
	}
}

//Check if map is enclosed in walls
void	ft_check_boundary(t_vars *vars, int i, int j)
{
	if ((i == 0 || i == vars->map.height - 1)
		&& (vars->map.grid[i][j] != '1'))
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Leaky Walls.\n", 6);
	}
	if ((j == 0 || j == vars->map.width - 1)
		&& (vars->map.grid[i][j] != '1'))
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Leaky Walls.\n", 6);
	}
}

// Check if theres unwanted character in map
void	ft_check_unwanted(t_vars *vars, int i, int j)
{
	if (vars->map.grid[i][j] != '1' && vars->map.grid[i][j] != '0' &&
		vars->map.grid[i][j] != 'C' && vars->map.grid[i][j] != 'E' &&
		vars->map.grid[i][j] != 'P' && vars->map.grid[i][j] != 'L')
	{
		ft_free_map(vars->map.grid);
		ft_exit_err("Unwanted Character in Map.\n", 5);
	}
}
