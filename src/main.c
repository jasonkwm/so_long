/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:18:19 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 20:26:10 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mini_main(t_vars *vars);

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		ft_exit_err("Invalid Number of Arguments.\n", 1);
	else
		vars.map.grid = ft_parse_map(av[1]);
	ft_temp_count(&vars);
	ft_init_pos(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * FS,
			vars.map.height * FS, "SO LONG DOLPHINS!!!");
	ft_mini_main(&vars);
	ft_free_map(vars.map.grid);
	system("leaks so_long");
	return(0);
}

void	ft_mini_main(t_vars *vars)
{
	ft_assign_art(vars);
	ft_print_static(vars);
	mlx_loop_hook(vars->mlx, &ft_looping_hookers, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 2147483647, "0");
	mlx_loop(vars->mlx);
}

// Initialize Positions 
void	ft_init_pos(t_vars *vars)
{
	vars->count = 0;
	vars->map.height = 0;
	vars->map.width = 0;
	vars->pos.coin_count = 0;
	ft_run_check(vars);
}

void	ft_run_check(t_vars *vars)
{
	ft_check_grid(vars);
	ft_check_char(vars);
	ft_2d_loop(vars, &ft_check_boundary);
	ft_2d_loop(vars, &ft_check_unwanted);
	ft_2d_loop(vars, &ft_get_pos);
	printf("position cat - x: %i, y: %i\n", vars->pos.hero[0], vars->pos.hero[1]);
	printf("position ghost - x: %i, y: %i\n", vars->pos.enemy[0], vars->pos.enemy[1]);
	printf("coin count: %i\n", vars->pos.coin_count);
}

// Loop for map
// takes a functions that accept i and j for x and y
void	ft_2d_loop(t_vars *vars, void (*func)(t_vars *, int, int))
{
	int	i;
	int	j;

	i = -1;
	while (vars->map.grid[++i] != NULL)
	{
		j = -1;
		while (vars->map.grid[i][++j] != 0 && vars->map.grid[i][j] != '\n')
		{
			func(vars, i, j);
		}
	}
}

void	ft_get_pos(t_vars *vars, int i, int j)
{
	if (vars->map.grid[i][j] == 'P')
	{
		vars->pos.hero[0] = j;
		vars->pos.hero[1] = i;
	}
	else if (vars->map.grid[i][j] == 'L')
	{
		vars->pos.enemy[0] = j;
		vars->pos.enemy[1] = i;
	}
	else if (vars->map.grid[i][j] == 'E')
	{
		vars->pos.exit[0] = j;
		vars->pos.exit[1] = i;
	}
	else if (vars->map.grid[i][j] == 'C')
		vars->pos.coin_count += 1;
}
