/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:59:01 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/11 12:00:19 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 13 = W, 0 = A, 1 = S, 2 = D
// 126 = UP, 123 = LEFT, 125 = DOWN, 124 = RIGHT
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53 && ++(vars->move_count))
		ft_exit_program(vars, "K Bye.\n");
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
	{
		ft_move_hero(keycode, vars);
		vars->move_count += 1;
	}
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_move_enemy(keycode, vars);
	return (0);
}

// the int variable in hero logic accept x and y changes
void	ft_move_hero(int keycode, t_vars *vars)
{
	if (keycode == 13)
		ft_hero_logic(vars, 0, -1);
	if (keycode == 0)
		ft_hero_logic(vars, -1, 0);
	if (keycode == 1)
		ft_hero_logic(vars, 0, 1);
	if (keycode == 2)
		ft_hero_logic(vars, 1, 0);
}

// the int variable in hero logic accept x and y changes
void	ft_move_enemy(int keycode, t_vars *vars)
{
	if (keycode == 126)
		ft_enemy_logic(vars, 0, -1);
	if (keycode == 123)
		ft_enemy_logic(vars, -1, 0);
	if (keycode == 125)
		ft_enemy_logic(vars, 0, 1);
	if (keycode == 124)
		ft_enemy_logic(vars, 1, 0);
}

// the if statemenet checks at new position
// if enemy then lose
// if count then minus coin_count and move hero
// if empty then move to position
// if exit then check if coin_count is equals to 0
void	ft_hero_logic(t_vars *vars, int x, int y)
{
	if (vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] == 'L')
		ft_exit_program(vars, "You Lose!\n");
	else if (vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] == 'C')
	{
		vars->coin_count -= 1;
		vars->map.grid[vars->hero[0]][vars->hero[1]] = '0';
		vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] = 'P';
		vars->hero[0] += y;
		vars->hero[1] += x;
	}
	else if (vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] == '0')
	{
		vars->map.grid[vars->hero[0]][vars->hero[1]] = '0';
		vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] = 'P';
		vars->hero[0] += y;
		vars->hero[1] += x;
	}
	else if (vars->map.grid[vars->hero[0] + y][vars->hero[1] + x] == 'E')
	{
		if (vars->coin_count == 0)
			ft_exit_program(vars, "You Won!\n");
	}
}

// if statement checks at new position
// if player then game over
// if collectable then swap position with collectable
// if empty then move to position 
// ignore wall and exit
void	ft_enemy_logic(t_vars *vars, int x, int y)
{
	if (vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] == 'P')
		ft_exit_program(vars, "You Lose!\n");
	else if (vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] == '0')
	{
		vars->map.grid[vars->enemy[0]][vars->enemy[1]] = '0';
		vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] = 'L';
		vars->enemy[0] += y;
		vars->enemy[1] += x;
	}
	else if (vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] == 'C')
	{
		vars->map.grid[vars->enemy[0]][vars->enemy[1]] = 'C';
		vars->map.grid[vars->enemy[0] + y][vars->enemy[1] + x] = 'L';
		vars->enemy[0] += y;
		vars->enemy[1] += x;
	}
}
