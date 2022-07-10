/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoh <jakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:16:47 by jakoh             #+#    #+#             */
/*   Updated: 2022/07/10 20:13:55 by jakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FRAMES 12
# define FS 64
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int hero[2];
	int	enemy[2];
	int	exit[2];
	int	coin_count;
}		t_pos;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
}		t_map;

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
	t_img	coin5;
	t_img	tile;
	t_img	exit;
	t_img	wall;
}			t_art;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		count;
	t_art	arts;
	t_pos	pos;
	t_map	map;
}				t_vars;

// main.c
void	ft_init_pos(t_vars *vars);
void	ft_2d_loop(t_vars *vars, void (*func)(t_vars *, int, int));

// utils.c
void	ft_exit_program(t_vars *vars);
void	ft_exit_err(char *message, int err);
void	ft_free_map(char **str);
void	ft_single_frame(t_vars *vars, t_img piece, int x, int y);
int		ft_count_char(char **map, char c);

// arts.c
void	ft_assign_art(t_vars *vars);

// hooks.c
int		key_hook(int keycode, t_vars *vars);

// loops.c
int		ft_looping_hookers(t_vars *vars);
void	ft_image_god(t_vars *vars, t_img cat, t_img ghost, t_img coin);
void	ft_single_frame(t_vars *vars, t_img piece, int x, int y);

// maps.c
int		ft_count_char(char **map, char c);
char	**ft_parse_map(char *map);
void	ft_print_static(t_vars *vars);
void	ft_get_pos(t_vars *vars, int i, int j);

// check.c
void	ft_run_check(t_vars *vars);
void	ft_check_grid(t_vars *vars);
void	ft_check_char(t_vars *vars);
void	ft_check_boundary(t_vars *vars, int i, int j);
void	ft_check_unwanted(t_vars *vars, int i, int j);

// temp.c
void	ft_temp_walls(t_vars *vars);
void	ft_temp_count(t_vars *vars);

#endif
