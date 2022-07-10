/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:59:01 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 20:44:34 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 13 = W, 0 = A, 1 = S, 2 = D
// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
int	key_hook(int keycode, t_vars *vars)
{
	char	*str;

	if (keycode == 53 && ++(vars->count))
		ft_exit_program(vars);
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		;
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		;
	str = ft_itoa(vars->count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->arts.wall.img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xffffffff, str);
	free(str);
	return (0);
}

void	ft_move_hero(int keycode, t_vars *vars)
{
	// if new pos is enemy then die
	// if coin then minus coin_count
	// if exit then check coin_count
	// if coin_count != 0 do nothing
	// if new pos == wall do nothing

	if (keycode == 13)
	{
		// move up
		// y - 1;
		if (vars->map.grid[vars->pos.hero[1]][vars->pos.hero[0]])
			;
	}
	if (keycode == 0)
	{
		// move left
		// x - 1;
	}
	if (keycode == 1)
	{
		// move down
		// y + 1;
	}
	if (keycode == 2)
	{
		// move right
		// x + 1;
	}
	(void)keycode;
	(void)vars;
}

void	ft_move_enemy(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
}