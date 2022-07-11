/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:18:19 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 12:01:01 by jakoh            ###   ########.fr       */
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
	ft_init(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * FS,
			vars.map.height * FS, "SO LONG DOLPHINS!!!");
	ft_mini_main(&vars);
	ft_free_map(vars.map.grid);
	return (0);
}

// Initialize Positions 
// and run map checks
void	ft_init(t_vars *vars)
{
	vars->move_count = 0;
	vars->map.height = 0;
	vars->map.width = 0;
	vars->coin_count = 0;
	ft_check_grid(vars);
	ft_check_char(vars);
	ft_loop_map(vars, &ft_check_boundary);
	ft_loop_map(vars, &ft_check_unwanted);
	ft_loop_map(vars, &ft_get_pos);
}

void	ft_mini_main(t_vars *vars)
{
	ft_assign_art(vars);
	ft_print_base(vars);
	mlx_loop_hook(vars->mlx, &ft_animation, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
