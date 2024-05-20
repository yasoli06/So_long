/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:53 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/26 17:02:35 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		pos_h;
	int		pos_w;
	int		collect;
	int		moves;
	void	*right;
	void	*left;
	void	*down;
	void	*up;
	void	*dino;
	void	*dino_tras;
	void	*cave;
	void	*grass;
	void	*tree;
	void	*huevo;
	void	*img;

}				t_vars;

typedef struct s_img
{
	int		img_width;
	int		img_height;
	int		i;
	int		j;
}	t_img;

// GET_MAP //
int		map_name_is_correct(char *map_path);
char	*get_raw_map(char *map_path);
char	**get_map(int argc, char **argv, t_vars *vars);
void	flood_fill(char **map, int x, int y, t_vars *vars);
char	**final_map(int argc, char **argv, t_vars *vars);

//	CHECK_MAP // 
int		check_is_rectangular(char **map, t_vars *vars);
int		check_is_closed(char *raw_map);
int		check_min_size(t_vars *vars);
int		check_min_type_char(char *raw_map, t_vars *vars);
int		final_check(char **map, t_vars *vars, char *raw_map);

// GET_IMAGES //
void	put_image(t_vars *vars, t_img *img);
void	background(t_vars *vars, t_img	*img);
void	get_images(t_vars *vars, t_img	*img);
void	init_game(t_vars *vars, t_img *img);
//void	change_image(t_vars *vars, t_img *img, char *path);

// GAME //
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
int		key_press(int keycode, t_vars *vars);

// UTILS // 
int		strnendcmp(char *s1, const char *s2, size_t n);
int		count_char(char c, char *str);
int		count_char_map(char c, char **map);
void	p_position(t_vars *vars);

// EXIT_FREE //
char	*free_map(char **map);
int		exit_win(t_vars *vars);
int		exit_me(t_vars *vars);
int		error_exit(t_vars *vars);

#endif