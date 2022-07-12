/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:15:51 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/12 14:16:22 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Error Message
// Exit Number
void	ft_exit_err(char *message, int err)
{
	ft_putstr_fd(message, 2);
	exit(err);
}

// Exit program and destroy window
// use when user press ESC key
void	ft_exit_program(t_vars *vars, char *msg)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_exit_err(msg, 3);
}

// Just like freeing ft_split
// free 2d char array
void	ft_free_map(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}

// exit game when player click on X button
int	ft_exit_on_click(t_vars *vars)
{
	ft_exit_program(vars, "K Bye.");
	return (1);
}
