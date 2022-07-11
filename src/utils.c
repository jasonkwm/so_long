/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:01 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 12:00:44 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Loop for map
// takes a functions that accept i and j for x and y
void	ft_loop_map(t_vars *vars, void (*func)(t_vars *, int, int))
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.grid[++i] != NULL)
	{
		j = -1;
		while (vars->map.grid[i][++j] != 0 && vars->map.grid[i][j] != '\n')
			func(vars, i, j);
	}
}

// prints a tiles & the specified image/character
// to a specific location
void	ft_single_frame(t_vars *vars, t_img piece, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.tile.img,
		x * FS, y * FS);
	mlx_put_image_to_window(vars->mlx, vars->win, piece.img,
		x * FS, y * FS);
}

// count specific character in 2d map char arr
int	ft_count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	j = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (map[i][j] == c)
				count++;
		}
	}
	return (count);
}

// Get position of hero, enemy & get number of coin count
void	ft_get_pos(t_vars *vars, int i, int j)
{
	if (vars->map.grid[i][j] == 'P')
	{
		vars->hero[0] = i;
		vars->hero[1] = j;
	}
	else if (vars->map.grid[i][j] == 'L')
	{
		vars->enemy[0] = i;
		vars->enemy[1] = j;
	}
	else if (vars->map.grid[i][j] == 'C')
		vars->coin_count += 1;
}
