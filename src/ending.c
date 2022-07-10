/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:15:51 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 20:17:00 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Error Message
// Exit Number
void	ft_exit_err(char *message, int err)
{
	ft_putstr_fd(message, 2);
	system("leaks so_long");
	exit(err);
}

// Exit program and destroy window
// use when user press ESC key
void	ft_exit_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_exit_err("K Bye.\n", 3);
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