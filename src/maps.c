/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:51:28 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/09 12:44:17 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0 = Empty Space
// 1 = Wall
// C = Collectable
// E = Exit
// P = Player 
// L = Eu Lee
// 1920 / 64 = 30
// 1080 / 64 = 16.8

char	**ft_parse_map(char *map)
{
	int	fd;
	char	**store;
	char	*line;
	int		i;

	i = 0;
	store = ft_calloc(100, sizeof(char *));
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i > 40)
		{
			ft_free_map(store);
			ft_exit_err("Map too big.\n", 2);
		}
		store[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return store;
}

// prints static character
// tiles, walls and exit door
// will be call in the beginning
void	ft_print_static(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.grid[++i] != NULL)
	{
		j = -1;
		while (vars->map.grid[i][++j] != 0)
		{
			if (vars->map.grid[i][j] == '0')
					ft_single_frame(vars, vars->arts.tile, j, i);
			if (vars->map.grid[i][j] == '1')
					ft_single_frame(vars, vars->arts.wall, j, i);
			if (vars->map.grid[i][j] == 'E')
					ft_single_frame(vars, vars->arts.exit, j, i);
		}
	}
}
