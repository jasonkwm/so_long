/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:51:28 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 12:00:40 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0 = Empty Space
// 1 = Wall
// C = Collectable
// E = Exit
// P = Player 
// L = Eu Lee
char	**ft_parse_map(char *map)
{
	int		fd;
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
	return (store);
}

// Prints static character
// Tiles, walls and exit door
// Will be call in the beginning
void	ft_print_base(t_vars *vars)
{
	char	*str;

	ft_loop_map(vars, &ft_put_base);
	str = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xffffffff, str);
	free(str);
}

// This function is to be pass into ft_loop_map
// Which in turn will print static character
void	ft_put_base(t_vars *vars, int i, int j)
{
	if (vars->map.grid[i][j] == '0')
		ft_single_frame(vars, vars->arts.tile, j, i);
	if (vars->map.grid[i][j] == '1')
		ft_single_frame(vars, vars->arts.wall, j, i);
	if (vars->map.grid[i][j] == 'E')
		ft_single_frame(vars, vars->arts.exit, j, i);
}
