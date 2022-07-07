/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:16:47 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/07 09:38:28 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# ifndef FRAMES
#  define FRAMES 10
# endif

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_art 
{
	t_img	cat1;
	t_img	cat2;
	t_img	cat3;
	t_img	cat4;
	t_img	cat5;
	t_img	ghost1;
	t_img	ghost2;
	t_img	ghost3;
	t_img	ghost4;
	t_img	ghost5;
	t_img	coin1;
	t_img	coin2;
	t_img	coin3;
	t_img	coin4;
	t_img	tile;
	t_img	door;
	t_img	wall;
}			t_art;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	static int	count;
	t_art		arts;
}				t_vars;

void	ft_exit_program(t_vars *vars);

//arts.c
void	ft_assign_art(t_vars *vars);

#endif