/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:01 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 20:18:44 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_single_frame(t_vars *vars, t_img piece, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.tile.img,
			x * FS, y * FS);
	mlx_put_image_to_window(vars->mlx, vars->win, piece.img,
			x * FS, y * FS);
}

// count specific character in 2d map char arrr
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
		while(map[i][++j] != 0)
		{
			if (map[i][j] == c)
				count++;
		}
	}
	return (count);
}

char	ft_get_char(t_vars *vars, int x, int y)
{
	return (vars->map.grid[x][y]);
}