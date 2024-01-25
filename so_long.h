/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:53 by yaolivei          #+#    #+#             */
/*   Updated: 2024/01/25 19:12:29 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		mapa;
	int		x;
	int		y;
	void	*img;
	int		count;
	int		collect;
	int		exitable;
	int		check_coin;
}				t_vars;

typedef struct s_img
{
	char	*img_path;
	int		img_width;
	int		img_height;
}				t_img;

// GET_MAP //
int		map_name_is_correct(char *map_path);
char	*get_raw_map(char *map_path);
char	**load_map(int argc, char **argv, t_vars *vars);
int		exit_finder(char **map, int x, int y, t_vars *vars);
char	**map(int argc, char **argv, t_vars *vars);

//	CHECK_MAP // 
int		checks_in_raw_map_are_valids(char *raw_map, t_vars *vars);
int		is_closed_map(char **map, t_vars *vars);
int		raw_map_is_rectangular(char *raw_map, t_vars *vars);
int		check_min_posible_map(t_vars *vars);
int		check_only_valid_character(char *raw_map, t_vars *vars);

// FREE //
char	*free_map(char **map);

// UTILS // 

int		strnendcmp(char *s1, const char *s2, size_t n);
int		count_char(char c, char *str);

// GET_IMAGES
int		closes(int keycode, t_vars *vars);
void	get_images(t_vars *vars, t_img	*img);
void	background(t_vars *vars, t_img	*img);
void	init_game(t_vars *vars, t_img	*img);

#endif